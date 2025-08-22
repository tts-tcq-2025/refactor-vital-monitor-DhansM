#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

/*int vitalsOk(float temperature, float pulseRate, float spo2) {
  if (temperature > 102 || temperature < 95) {
    cout << "Temperature is critical!\n";
    for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
    return 0;
  } else if (pulseRate < 60 || pulseRate > 100) {
    cout << "Pulse Rate is out of range!\n";
    for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
    return 0;
  } else if (spo2 < 90) {
    cout << "Oxygen Saturation out of range!\n";
    for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
    return 0;
  }
  return 1;
}*/


void showAlert(const std::string& message) {
    cout << message << "\n";
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        this_thread::sleep_for(seconds(1));
        cout << "\r *" << flush;
        this_thread::sleep_for(seconds(1));
    }
}

bool isTemperatureOk(float temperature) {
    return temperature >= 95 && temperature <= 102;
}

bool isPulseRateOk(float pulseRate) {
    return pulseRate >= 60 && pulseRate <= 100;
}

bool isSpo2Ok(float spo2) {
    return spo2 >= 90;
}


int vitalsOk(float temperature, float pulseRate, float spo2) {
    if (!checkVital("Temperature", temperature, 95.0, 102.0)) return 0;
    if (!checkVital("Pulse Rate", pulseRate, 60.0, 100.0)) return 0;
    if (!checkVital("Oxygen Saturation", spo2, 90.0, 100.0)) return 0;
    return 1;
}



