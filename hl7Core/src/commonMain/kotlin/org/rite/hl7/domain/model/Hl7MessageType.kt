package org.rite.hl7.domain.model

/**
 * Classifies a parsed HL7 message into a business action type.
 *
 * Resolution order matters — more specific checks (CANCEL, INVENTORY_RESPONSE)
 * come before broader ones (DISPENSE, INVENTORY_UPDATE).
 */
enum class Hl7MessageType {

    /** RDS^O13 with ORC-1=RE — robot dispensed medication to patient **/
    DISPENSE,

    /** RDE^O11 — pharmacy order sent to robot for verification/fill **/
    DISPENSE_ORDER,

    /** ORC-1=CA on any message type — cancel a pending order **/
    CANCEL_ORDER,

    /** INR^U06 — PMS requesting inventory count from robot **/
    INVENTORY_REQUEST,

    /** INR^U05 with ORC-1=RE — robot sending count results back to PMS **/
    INVENTORY_RESPONSE,

    /** INU^U05 — robot pushing unsolicited inventory update to PMS **/
    INVENTORY_UPDATE,

    /** ACK — acknowledgment or rejection of a prior message **/
    ACKNOWLEDGMENT,

    /** Message could not be classified — inspect messageType/triggerEvent manually **/
    UNKNOWN;

    companion object {

        /**
         * Derives the message type from a parsed [CompleteHL7Message].
         * Called automatically during parsing — available as [CompleteHL7Message.hl7MessageType].
         */
        fun from(message: CompleteHL7Message): Hl7MessageType {
            val type    = message.messageType.uppercase()
            val trigger = message.triggerEvent.uppercase()
            val control = message.order?.orderControl?.uppercase()

            return when {

                // Cancel order — ORC-1=CA takes priority over message type
                control == "CA" && !message.order?.placerOrderId.isNullOrBlank() ->
                    CANCEL_ORDER

                // Dispense result — RDS^O13 with ORC-1=RE
                type == "RDS" && trigger == "O13" && control == "RE" ->
                    DISPENSE

                // Pharmacy order — RDE^O11
                type == "RDE" && trigger == "O11" ->
                    DISPENSE_ORDER

                // Inventory count response — INR^U05 sent by robot back to PMS
                type == "INR" && trigger == "U05" ->
                    INVENTORY_RESPONSE

                // Inventory count request — INR^U06 sent by PMS to robot
                type == "INR" && trigger == "U06" ->
                    INVENTORY_REQUEST

                // Inventory update — INU^U05 unsolicited push from robot
                type == "INU" && trigger == "U05" ->
                    INVENTORY_UPDATE

                // ACK — positive or negative acknowledgment
                type == "ACK" ->
                    ACKNOWLEDGMENT

                else -> UNKNOWN
            }
        }
    }
}
