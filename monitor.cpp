#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
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
    for (int i = 0; i < 6; ++i) {
        cout << "\r* " << flush;
        this_thread::sleep_for(seconds(1));
        cout << "\r *" << flush;
        this_thread::sleep_for(seconds(1));
    }
}

struct Vital {
    std::string name;
    float value;
    float min;
    float max;
};

bool checkVital(const Vital& vital) {
    if (vital.value < vital.min || vital.value > vital.max) {
        showAlert(vital.name + " is out of range!");
        return false;
    }
    return true;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    std::vector<Vital> vitals = {
        {"Temperature", temperature, 95.0, 102.0},
        {"Pulse Rate", pulseRate, 60.0, 100.0},
        {"Oxygen Saturation", spo2, 90.0, 100.0}
    };

    for (const auto& vital : vitals) {
        if (!checkVital(vital)) {
            return 0;
        }
    }
    return 1;
}




