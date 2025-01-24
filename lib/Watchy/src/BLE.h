#ifndef _BLE_H_
#define _BLE_H_

#include <BLE2902.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>

#include "Arduino.h"
#include "config.h"
#include "esp_ota_ops.h"

class BLE;

class BLE {
   public:
    BLE(void);
    ~BLE(void);

    bool begin(const char *localName);
    int updateStatus();
    int howManyBytes();

   private:
    String local_name;

    BLEServer *pServer = NULL;

    BLEService *pESPOTAService = NULL;
    BLECharacteristic *pESPOTAIdCharacteristic = NULL;

    BLEService *pService = NULL;
    BLECharacteristic *pVersionCharacteristic = NULL;
    BLECharacteristic *pOtaCharacteristic = NULL;
    BLECharacteristic *pWatchFaceNameCharacteristic = NULL;
};

#endif
