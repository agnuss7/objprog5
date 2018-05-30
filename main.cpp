#include "functions.hpp"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"


TEST_CASE( "konteineriai uzpildomi", "[multimap]" ) {

    std::multimap<std::string,int> a;
    std::set<std::string> B;
    REQUIRE( a.max_size()>0);
    REQUIRE( B.max_size()>0);
    SECTION( "insert" ) {
        int s=a.size();
        a.insert(std::pair<std::string,int>("hello",2));
        REQUIRE( a.size()>s );
    }
    SECTION( "spausdinama" ) {
        read(a,B,"tekstas.txt");
        print(a,B);
    }
}

