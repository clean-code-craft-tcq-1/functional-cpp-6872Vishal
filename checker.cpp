#include <assert.h>
#include <iostream>
using namespace std;

class BMS{
  private:
    bool BMS_OK;
  public:
    BMS()
    { BMS_OK = true; }
    void Check_Parameters(float parameter,float max,float min)
    {
      if(parameter < min || parameter > max)
      {
        BMS_OK = false;
      } 
    }
  bool Send_BMS_Result()
  {
    return BMS_OK;
  }
  ~BMS();
};
// void Temperature_within_Limit(float temperature)
// {
//   if(temperature < 0 || temperature > 45) {
//     cout << "Temperature out of range!\n";
//     result = false;
    
//   }
  
// }
// void SOC_within_Limit(float soc)
// {
//   if(soc < 20 || soc > 80) {
//     cout << "State of Charge out of range!\n";
//     result = false;
//   }
  
// }
// void Check_ChargeRate_Threshold(float chargeRate)
// {
//   if(chargeRate < 0 || chargeRate > 0.8) {
//     cout << "Charge Rate out of range!\n";
//     result = false;
//   }
  
}
bool batteryIsOk(float temperature, float soc, float chargeRate) {
  
  class BMS class_obj;
  class_obj.Check_Parameters(temperature,45,0);
  class_obj.Check_Parameters(soc,80,20);
  class_obj.Check_Parameters(chargeRate,0.8,0);
//   Temperature_within_Limit(temperature);
//   SOC_within_Limit(soc);
//   Check_ChargeRate_Threshold(chargeRate);

//   if(result == false)
//   {
//     result = true;
//     return false;
//   }
//   return true;
  return class_obj.Send_BMS_Result();
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
