#pragma once
#include <cstddef>
#include <string>

#include "StructsForShip.hpp"

enum class ShipResponse;

class ShipInterface {
public:
  virtual ~ShipInterface() = default; 
  
  virtual const std::string &getShipType() const = 0;
  virtual const Speed& getSpeed() const = 0;
  virtual const Turning& getTurning() const = 0;
  virtual const Crew& getCrew() const = 0;
  virtual const Capacity& getCapacity() const = 0;
  virtual const Cannons& getCannons() const = 0;
  virtual const HP& getHP() const = 0;
  virtual const Upkeep& getUpkeep() const = 0;
  virtual const Cost& getCost() const = 0;
  virtual const std::string &getName() const = 0;  

  virtual void setShipType(const std::string&) = 0;
  virtual void setSpeed(const Speed&) = 0;
  virtual void setTurning(const Turning&) = 0;
  virtual void setCrew(const Crew&) = 0;
  virtual void setMaxCrew(const Crew&) = 0;
  virtual void setCapacity(const Capacity&) = 0;
  virtual void setMaxCapacity(const Capacity&) = 0;
  virtual void setCannons(const Cannons&) = 0;
  virtual void setMaxCannons(const Cannons&) = 0;
  virtual void setHP(const HP&) = 0;
  virtual void setUpkeep(const Upkeep&) = 0;
  virtual void setCost(const Cost&) = 0;
  virtual void setName(const std::string) = 0;

  virtual ShipResponse subtractCrew(Crew crewNum) = 0;  
  virtual ShipResponse subtractCapacity(Capacity capacityNum) = 0; 
  virtual ShipResponse subtractCannons(Cannons cannonsNum) = 0; 
  virtual ShipResponse subtractHP(HP hpNum) = 0;

  virtual ShipResponse addCrew(Crew crewNum) = 0;  
  virtual ShipResponse addCapacity(Capacity capacityNum) = 0;  
  virtual ShipResponse addCannons(Cannons cannonsNum) = 0; 
  virtual ShipResponse addHP(HP hpNum) = 0;
}; 
