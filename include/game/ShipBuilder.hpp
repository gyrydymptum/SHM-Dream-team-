#pragma once 

#include "Ship.hpp"

#include <memory>
class ShipInterface;

class ShipBuilder {
    std::shared_ptr<ShipInterface> ship_;
    
    public:
    ShipBuilder(ShipInterface* shipInterface) : ship_{shipInterface} {} 

    std::shared_ptr<ShipInterface> get() {
        return std::move(ship_);
    }
    
    ShipBuilder& setShipType(const std::string&);
    ShipBuilder& setSpeed(const Speed&);
    ShipBuilder& setTurning(const Turning&);
    ShipBuilder& setMaxCrew(const Crew&);
    ShipBuilder& setMaxCapacity(const Capacity&);
    ShipBuilder& setMaxCannons(const Cannons&);
    ShipBuilder& setUpkeep(const Upkeep&);
    ShipBuilder& setCost(const Cost&);
    ShipBuilder& setName(const std::string&);
    ShipBuilder& setCrew(const Crew&);
    ShipBuilder& setCapacity(const Capacity&);
    ShipBuilder& setCannons(const Cannons&);
    ShipBuilder& setHP(const HP&);
}; 
