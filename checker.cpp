#include <assert.h>
#include <iostream>
using namespace std;

bool result = true;
void Temperature_within_Limit(float temperature)
{
  if(temperature < 0 || temperature > 45) {
    cout << "Temperature out of range!\n";
    result = false;
    
  }
  
}
void SOC_within_Limit(float soc)
{
  if(soc < 20 || soc > 80) {
    cout << "State of Charge out of range!\n";
    result = false;
  }
  
}
void Check_ChargeRate_Threshold(float chargeRate)
{
  if(chargeRate < 0 || chargeRate > 0.8) {
    cout << "Charge Rate out of range!\n";
    result = false;
  }
  
}
bool batteryIsOk(float temperature, float soc, float chargeRate) {
  
  Temperature_within_Limit(temperature);
  SOC_within_Limit(soc);
  Check_ChargeRate_Threshold(chargeRate);

  if(result == false)
  {
    result = true;
    return false;
  }
  return true;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  assert(batteryIsOk(50, 85, -0.5) == false);
}
