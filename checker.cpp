#include <assert.h>
#include <iostream>
using namespace std;

enum BMS_Parameters {Temperature,Sate_of_Charge,Charge_Rate};
const char* BMS_Parameters_Name[] = { "Temperature" ,"SOC" , "ChargeRate" };

enum BMS_Parameters_Min_Value {Temperature_Min = 0,  SOC_Min = 20, ChargeRate_Min = 0.0};
enum BMS_Parameters_Max_Value {Temperature_Max = 45, SOC_Max = 80, ChargeRate_Max = 0.8};

class BMS{
  private:
    bool BMS_OK;
  public:
    BMS()
    { BMS_OK = true; }
    void Check_Parameters(float parameter,float max,float min,BMS_Parameters name)
    {
      if(parameter < min || parameter > max)
      {
        cout <<BMS_Parameters_Name[name]<<" is out of range! \n";
        BMS_OK = false;
      } 
    }
  bool Send_BMS_Result()
  {
    return BMS_OK;
  }
  
};

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  class BMS class_obj;
  class_obj.Check_Parameters(temperature,Temperature_Max,Temperature_Min,Temperature);
  class_obj.Check_Parameters(soc,SOC_Max,SOC_Min,Sate_of_Charge);
  class_obj.Check_Parameters(chargeRate,ChargeRate_Max,ChargeRate_Min,Charge_Rate);
  return class_obj.Send_BMS_Result();
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
