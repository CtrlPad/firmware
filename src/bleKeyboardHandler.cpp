#include <Arduino.h>
#include <BLE2902.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <bleKeyboardHandler.h>
#include <configReceiver.h>

#define SERVICE_UUID "a3308e24-786f-40b3-bf31-308875404027"
#define CHARACTERISTIC_UUID "62148466-62a9-4f65-bc29-2c2e408b8684"

BLEServer *pServer = nullptr;
BLECharacteristic *pCharacteristic = nullptr;
bool deviceConnected = false;

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *pServer) {
    deviceConnected = true;
    Serial.println("Connection received");
  }

  void onDisconnect(BLEServer *pServer) {
    deviceConnected = false;
    Serial.println("Disconnection received");
    pServer->startAdvertising();
  }
};

// Data Callbacks
class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pChar) override {
    std::string value = pChar->getValue();
    processIncomingConfig(value.c_str());
  }
};

void initBLEKeyboard() {
  BLEDevice::init("ctrlPad_BLE");      // INit BLE
  pServer = BLEDevice::createServer(); // crete BLE Server
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID); // BLE Service
  pCharacteristic = pService->createCharacteristic( // BLE Characteristic
      CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_NOTIFY);

  pCharacteristic->setCallbacks(new MyCharacteristicCallbacks());
  pCharacteristic->addDescriptor(new BLE2902());

  pService->start(); // start servie
  BLEAdvertising *pAdvertising =
      BLEDevice::getAdvertising(); // start advertising
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->start();
}

void sendBLENotify(uint32_t messageId) {
  if (deviceConnected) {
    String messageStr = String(messageId);
    pCharacteristic->setValue(messageStr.c_str());
    pCharacteristic->notify();
    Serial.print("Notified: ");
    Serial.println(messageId);
  }
}
