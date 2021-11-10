#include "../include/game/Game.hpp" //to było

#include <iostream>

#include "../include/game/Ship.hpp"
#include "../include/game/ShipBuilder.hpp"
#include "../utility/json/JsonSerializer.hpp"

int main() {
    auto game = Game::create("config.json");
    if(game) {
        if(game->init()){
            game->run();
        }
    }
    

    auto ship = Ship::create().setShipType("Galeon")
                            .setSpeed(Speed{15})
                            .setTurning(Turning{80})
                            .setCrew(Crew{60, 200})
                            .setMaxCrew(Crew{60, 200})
                            .setCapacity(Capacity{150, 400})
                            .setMaxCapacity(Capacity{150, 400})
                            .setCannons(Cannons{10, 20})
                            .setMaxCannons(Cannons{10, 20})
                            .setHP(HP{70})
                            .setUpkeep(Upkeep{250})
                            .setCost(Cost{10'000})
                            .setName("Black Pearl").get();

    std::cout << typeid(ship).name() << '\n';


    std::cout << ship->getName() << '\n';
JsonSerializer::clear();
    JsonSerializer::put("ships", ship);
    
    JsonSerializer::save("Ship.json");
    
    JsonSerializer::clear();
    return 0;

}
