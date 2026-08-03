#include "zombie.hpp"

void randomChump( std::string name)
{
    Zombie z(name);
    z.announce();
}