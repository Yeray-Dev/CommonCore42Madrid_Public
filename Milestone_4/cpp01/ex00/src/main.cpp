#include "zombie.hpp"

int main( void )
{
    Zombie *z = newZombie("bob");
    z->announce();
    delete z;

    randomChump("Fred");
}