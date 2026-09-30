package org.rite.hl7.util

import platform.Foundation.NSDate
import platform.Foundation.NSDateFormatter
import platform.Foundation.NSTimeZone
import platform.Foundation.localTimeZone

actual fun currentLocalDateTime(): String {
    val date = NSDate()
    val formatter =
        NSDateFormatter().apply {
            dateFormat = "yyyy-MM-dd'T'HH:mm:ss"
            timeZone = NSTimeZone.localTimeZone
        }
    return formatter.stringFromDate(date)
}
