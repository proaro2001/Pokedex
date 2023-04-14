
#include "pokedex.h"
#include <iostream>
#include <string>

using namespace std;

// Your code goes here

  // constructor - create empty Pokedex
Pokedex::Pokedex (){
}

  // Return size
int Pokedex::size() const{
    return msize;
}

  // Return maximum size, capacity of Pokedex
int Pokedex::max_size () {
    return MAX;
}

  // return true if Pokedex is empty
bool Pokedex::empty() const {
    return msize == 0;
}

  // return pokemon at given index
  // undefined behaviour for n < 0 or n >= size
const string & Pokedex::at (int n ) const {
    if ( n < 0 || n >= msize ) { //invalid parameters case
        cout << "Invalid n" << endl;
        return front(); //return the first element
    } 
    return pokemons[n];
    
}

// return pokemon at the front, alphabetically first one
const string & Pokedex::front () const {
    return pokemons[0];
}

// return pokemon at the front, alphabetically last one
const string & Pokedex::back () const {
    return pokemons[msize - 1];
}

//   Add pokemon to Pokedex, keep the Pokedex list sorted
  // Can have multiple pokemon with the same name
  // Pokemon is not inserted if Pokedex is already full
void Pokedex::insert ( const string &pokemon ) {
    //base case: empty
    if ( msize == 0 ) {
        pokemons[ msize ++ ] = pokemon;
        return; //it stops the function continue but the main program keeps running
    }
    //base case: full
    if ( msize ==  MAX ) {
        cerr << "No space for "<< pokemon << endl; //error message 
        return; //exit the function
    }
    //normal situation
    //first insert the pokemon to the array , the use bubble sort to sort it 
    int index = 0;  //index creates to determine which 

    //when index is smaller than the msize and pokemon is still larger than the 
    //compare object, it means it is not the place, then we move on
    while ( index < msize && pokemon.compare(pokemons[index]) >= 0){
        index++;
    }

    //moves everything backward until j reaches index
    for ( int j = msize; j > index ; j -- ){
        pokemons[j] = pokemons[j-1];
    }
    msize ++; //indicate one pokemon is stores
    pokemons[index] = pokemon; //put pokemon into the array pokemons 
}

// Delete the last element
void Pokedex::pop_back (){
    if ( msize > 0 )
        pokemons[--msize] = "" ;
}

  // Erase element at location, move other elements as needed
  // undefined behaviour if given index is not valid
void Pokedex::erase ( int n ){
    //invalid input
    if ( n < 0 || n >= msize ){
        cerr << "Invalid input n " << n << endl;
    }
    //normal case
    msize --;
    //move everything forward
   for ( int i = n ; i < msize  ;i ++){
    pokemons[i] = pokemons[i+1];
   }
}

// insertion operator, so we can use "cout << pdx"
ostream &operator<<(ostream &out, const Pokedex &pdx){
    out << '[';
    string temp = "";
    for ( int i = 0 ; i < pdx.size(); i ++ ){
        if ( i != pdx.size() - 1 )
            temp += pdx.at(i) + ", ";
        else 
            temp += pdx.at ( i );
    }
    out << temp << ']';
return out;
}