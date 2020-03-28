#include "RecordInterface.h"
#include "IcpRecord.h"

RecordInterface* RecordInterface::get_record() {
    //RecordType record_type = (RecordType)GetConfigValue("CommuncationConfig", "Camera", "type").toInt();
    switch (1) {
    case TypeUsbRecord:
        //return VideoRecord::instance();
        break;
    case TypeIpcRecord:
        return IcpRecord::instance();
        break;
    default:
        break;
    }
    //return VideoRecord::instance();
}

