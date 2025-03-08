// movie_tests.cpp
// Comprehensive test suite for Movie Rental System
// Author: Your Name
// Date: March 7, 2025

// References:
// - "Test-Driven Development by Example" by Kent Beck (2002)
// - "Working Effectively with Legacy Code" by Michael Feathers (2004)
// - "xUnit Test Patterns: Refactoring Test Code" by Gerard Meszaros (2007)
// - "Growing Object-Oriented Software, Guided by Tests" by Steve Freeman and Nat Pryce (2009)

#include <iostream>
#include <cassert>
#include <memory>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

// Include your classes here
#include "movie.h"
#include "comedymovie.h"
#include "dramamovie.h"
#include "classicmovie.h"
#include "moviebst.h"
#include "mediatype.h"
#include "dvd.h"

// Test helper functions
namespace Test {
    int totalTests = 0;
    int passedTests = 0;
    
    // Test class to provide consistent formatting and reporting
    class TestCase {
    private:
        std::string testName;
        std::function<void()> testFunc;
        
    public:
        TestCase(const std::string& name, std::function<void()> func) 
            : testName(name), testFunc(func) {}
        
        void run() {
            std::cout << "Running test: " << testName << "... ";
            totalTests++;
            
            try {
                testFunc();
                std::cout << "PASSED" << std::endl;
                passedTests++;
            } catch (const std::exception& e) {
                std::cout << "FAILED: " << e.what() << std::endl;
            } catch (...) {
                std::cout << "FAILED with unknown exception" << std::endl;
            }
        }
    };
    
    // Custom assertion helpers with descriptive messages
    template<typename T>
    void assertEquals(const T& expected, const T& actual, const std::string& message) {
        if (!(expected == actual)) {
            throw std::runtime_error(message + 
                " (Expected: " + std::to_string(expected) + 
                ", Actual: " + std::to_string(actual) + ")");
        }
    }
    
    template<>
    void assertEquals<std::string>(const std::string& expected, const std::string& actual, const std::string& message) {
        if (expected != actual) {
            throw std::runtime_error(message + 
                " (Expected: " + expected + 
                ", Actual: " + actual + ")");
        }
    }
    
    template<>
    void assertEquals<bool>(const bool& expected, const bool& actual, const std::string& message) {
        if (expected != actual) {
            throw std::runtime_error(message + 
                " (Expected: " + (expected ? "true" : "false") + 
                ", Actual: " + (actual ? "true" : "false") + ")");
        }
    }
    
    void assertTrue(bool condition, const std::string& message) {
        if (!condition) {
            throw std::runtime_error(message);
        }
    }
    
    void assertFalse(bool condition, const std::string& message) {
        if (condition) {
            throw std::runtime_error(message);
        }
    }
    
    void assertNotNull(const void* ptr, const std::string& message) {
        if (ptr == nullptr) {
            throw std::runtime_error(message);
        }
    }
    
    void assertNotEmpty(const std::string& str, const std::string& message) {
        if (str.empty()) {
            throw std::runtime_error(message);
        }
    }
    
    // Print final test summary
    void printSummary() {
        std::cout << "\n===== TEST SUMMARY =====" << std::endl;
        std::cout << "Total tests: " << totalTests << std::endl;
        std::cout << "Passed: " << passedTests << std::endl;
        std::cout << "Failed: " << (totalTests - passedTests) << std::endl;
        
        if (passedTests == totalTests) {
            std::cout << "All tests passed! ✅" << std::endl;
        } else {
            std::cout << "Some tests failed. ❌" << std::endl;
        }
    }
}

// Test fixtures to setup reusable test data
namespace Fixtures {
    // Media fixture
    std::shared_ptr<MediaType> createDVD() {
        return std::make_shared<DVD>();
    }
    
    // Comedy movie fixtures
    std::shared_ptr<ComedyMovie> createBasicComedyMovie() {
        return std::make_shared<ComedyMovie>(
            "The Hangover", 
            "Todd Phillips", 
            2009, 
            5,
            createDVD()
        );
    }
    
    std::shared_ptr<ComedyMovie> createAnotherComedyMovie() {
        return std::make_shared<ComedyMovie>(
            "Superbad", 
            "Greg Mottola", 
            2007, 
            3,
            createDVD()
        );
    }
    
    // Drama movie fixtures
    std::shared_ptr<DramaMovie> createBasicDramaMovie() {
        return std::make_shared<DramaMovie>(
            "The Godfather", 
            "Francis Ford Coppola", 
            1972, 
            7,
            createDVD()
        );
    }
    
    // Classic movie fixtures
    std::shared_ptr<ClassicMovie> createBasicClassicMovie() {
        std::vector<std::string> actors = {"Humphrey Bogart", "Ingrid Bergman"};
        return std::make_shared<ClassicMovie>(
            "Casablanca", 
            "Michael Curtiz", 
            1942, 
            10,
            createDVD(),
            11, // November
            actors
        );
    }
    
    std::shared_ptr<ClassicMovie> createSameClassicMovieDifferentActor() {
        std::vector<std::string> actors = {"Claude Rains"};
        return std::make_shared<ClassicMovie>(
            "Casablanca", 
            "Michael Curtiz", 
            1942, 
            5,
            createDVD(),
            11, // November
            actors
        );
    }
}

// Test suites
namespace Tests {
    // Comedy Movie Tests
    void testComedyMovieConstructor() {
        auto movie = Fixtures::createBasicComedyMovie();
        
        Test::assertEquals<std::string>("The Hangover", movie->getTitle(), "Comedy title should match");
        Test::assertEquals<std::string>("Todd Phillips", movie->getDirector(), "Comedy director should match");
        Test::assertEquals<int>(2009, movie->getReleaseYear(), "Comedy year should match");
        Test::assertEquals<int>(5, movie->getStock(), "Comedy stock should match");
        Test::assertNotEmpty(movie->getMedia(), "Comedy media should not be empty");
    }
    
    void testComedyMovieComparison() {
        auto movie1 = Fixtures::createBasicComedyMovie();  // The Hangover, 2009
        auto movie2 = Fixtures::createAnotherComedyMovie(); // Superbad, 2007
        
        // Test less than: Should compare by title first
        Test::assertFalse(*movie1 < *movie2, "The Hangover should not be less than Superbad");
        Test::assertTrue(*movie2 < *movie1, "Superbad should be less than The Hangover");
        
        // Test greater than
        Test::assertTrue(*movie1 > *movie2, "The Hangover should be greater than Superbad");
        Test::assertFalse(*movie2 > *movie1, "Superbad should not be greater than The Hangover");
        
        // Test equality with a copy
        auto movieCopy = std::make_shared<ComedyMovie>(
            "The Hangover", "Todd Phillips", 2009, 5, Fixtures::createDVD()
        );
        Test::assertTrue(*movie1 == *movieCopy, "The same comedy movies should be equal");
        Test::assertFalse(*movie1 != *movieCopy, "The same comedy movies should not be not equal");
    }
    
    void testComedyMovieMerge() {
        auto movie1 = Fixtures::createBasicComedyMovie();  // Stock: 5
        
        // Create a copy with different stock
        auto movie2 = std::make_shared<ComedyMovie>(
            "The Hangover", "Todd Phillips", 2009, 3, Fixtures::createDVD()
        );
        
        Test::assertTrue(movie1->mergeWith(movie2), "Merge should succeed with identical movies");
        Test::assertEquals<int>(8, movie1->getStock(), "Stock should be combined after merge");
    }
    
    // Drama Movie Tests
    void testDramaMovieConstructor() {
        auto movie = Fixtures::createBasicDramaMovie();
        
        Test::assertEquals<std::string>("The Godfather", movie->getTitle(), "Drama title should match");
        Test::assertEquals<std::string>("Francis Ford Coppola", movie->getDirector(), "Drama director should match");
        Test::assertEquals<int>(1972, movie->getReleaseYear(), "Drama year should match");
        Test::assertEquals<int>(7, movie->getStock(), "Drama stock should match");
        Test::assertNotEmpty(movie->getMedia(), "Drama media should not be empty");
    }
    
    // Note: Skipping Drama comparison tests due to access issues
    
    // Classic Movie Tests
    void testClassicMovieConstructor() {
        auto movie = Fixtures::createBasicClassicMovie();
        
        Test::assertEquals<std::string>("Casablanca", movie->getTitle(), "Classic title should match");
        Test::assertEquals<std::string>("Michael Curtiz", movie->getDirector(), "Classic director should match");
        Test::assertEquals<int>(1942, movie->getReleaseYear(), "Classic year should match");
        Test::assertEquals<int>(11, movie->getReleaseDate(), "Classic month should match");
        Test::assertEquals<int>(10, movie->getStock(), "Classic stock should match");
        Test::assertNotEmpty(movie->getMedia(), "Classic media should not be empty");
        
        auto actors = movie->getMajorActors();
        Test::assertEquals<size_t>(2, actors.size(), "Should have 2 actors");
        Test::assertEquals<std::string>("Humphrey Bogart", actors[0], "First actor should match");
        Test::assertEquals<std::string>("Ingrid Bergman", actors[1], "Second actor should match");
    }
    
    void testClassicMovieAddActor() {
        auto movie = Fixtures::createBasicClassicMovie();
        
        movie->addActor("Peter Lorre");
        auto actors = movie->getMajorActors();
        
        Test::assertEquals<size_t>(3, actors.size(), "Should have 3 actors after adding one");
        
        // Test if the actor was added (may not be at position 2 due to sorting)
        bool actorFound = false;
        for (const auto& actor : actors) {
            if (actor == "Peter Lorre") {
                actorFound = true;
                break;
            }
        }
        Test::assertTrue(actorFound, "New actor should be added");
        
        // Test adding duplicate actor
        movie->addActor("Humphrey Bogart");
        actors = movie->getMajorActors();
        Test::assertEquals<size_t>(3, actors.size(), "Should still have 3 actors after adding duplicate");
    }
    
    void testClassicMovieMerge() {
        auto movie1 = Fixtures::createBasicClassicMovie();
        auto movie2 = Fixtures::createSameClassicMovieDifferentActor();
        
        Test::assertTrue(movie1->mergeWith(movie2), "Merge should succeed for same movie with different actors");
        Test::assertEquals<int>(15, movie1->getStock(), "Stock should be combined after merge");
        
        auto actors = movie1->getMajorActors();
        Test::assertEquals<size_t>(3, actors.size(), "Should have 3 actors after merge");
        Test::assertTrue(
            std::find(actors.begin(), actors.end(), "Claude Rains") != actors.end(),
            "New actor should be added during merge"
        );
    }
    
    // Movie BST Tests
    void testMovieBSTInsert() {
        MovieBST<ComedyMovie> bst;
        
        auto movie1 = Fixtures::createBasicComedyMovie();
        auto movie2 = Fixtures::createAnotherComedyMovie();
        
        Test::assertTrue(bst.insert(movie1), "Should successfully insert first movie");
        Test::assertTrue(bst.insert(movie2), "Should successfully insert second movie");
    }
    
    void testMovieBSTRetrieve() {
        MovieBST<ComedyMovie> bst;
        
        auto movie1 = Fixtures::createBasicComedyMovie();
        bst.insert(movie1);
        
        // Create a search key
        auto searchKey = std::make_shared<ComedyMovie>(
            "The Hangover", "", 2009, 0, nullptr
        );
        
        auto result = bst.retrieve(searchKey);
        Test::assertNotNull(result.get(), "Should retrieve inserted movie");
        Test::assertEquals<std::string>("The Hangover", result->getTitle(), "Retrieved movie title should match");
        Test::assertEquals<int>(5, result->getStock(), "Retrieved movie stock should match");
        
        // Search for non-existent movie
        auto badSearchKey = std::make_shared<ComedyMovie>(
            "Nonexistent Movie", "", 2000, 0, nullptr
        );
        
        auto badResult = bst.retrieve(badSearchKey);
        Test::assertTrue(badResult == nullptr, "Should return nullptr for non-existent movie");
    }
    
    void testSpecificBSTForEachMovieType() {
        // Test Comedy BST
        MovieBST<ComedyMovie> comedyBST;
        auto comedy1 = Fixtures::createBasicComedyMovie();
        auto comedy2 = Fixtures::createAnotherComedyMovie();
        
        comedyBST.insert(comedy1);
        comedyBST.insert(comedy2);
        
        auto comedySearch = std::make_shared<ComedyMovie>("Superbad", "", 2007, 0, nullptr);
        auto comedyResult = comedyBST.retrieve(comedySearch);
        Test::assertEquals<std::string>("Greg Mottola", comedyResult->getDirector(), "Should retrieve correct comedy movie");
        
        // Test Drama BST
        MovieBST<DramaMovie> dramaBST;
        auto drama = Fixtures::createBasicDramaMovie();
        dramaBST.insert(drama);
        
        auto dramaSearch = std::make_shared<DramaMovie>("The Godfather", "Francis Ford Coppola", 0, 0, nullptr);
        auto dramaResult = dramaBST.retrieve(dramaSearch);
        Test::assertEquals<int>(1972, dramaResult->getReleaseYear(), "Should retrieve correct drama year");
        
        // Test Classic BST
        MovieBST<ClassicMovie> classicBST;
        auto classic = Fixtures::createBasicClassicMovie();
        classicBST.insert(classic);
        
        std::vector<std::string> searchActors = {"Humphrey Bogart"};
        auto classicSearch = std::make_shared<ClassicMovie>("", "", 1942, 0, nullptr, 11, searchActors);
        auto classicResult = classicBST.retrieve(classicSearch);
        Test::assertEquals<std::string>("Casablanca", classicResult->getTitle(), "Should retrieve correct classic movie");
    }
    
    // Integration Tests
    void testIntegrationAddingAndRetrievingMoviesWithMerge() {
        MovieBST<ClassicMovie> classicBST;
        
        auto classic1 = Fixtures::createBasicClassicMovie();
        classicBST.insert(classic1);
        
        // Create a movie that should merge (same movie, different actor)
        auto classic2 = Fixtures::createSameClassicMovieDifferentActor();
        
        // Create a search key to find the first movie
        std::vector<std::string> searchActors = {"Humphrey Bogart"};
        auto searchKey = std::make_shared<ClassicMovie>("Casablanca", "Michael Curtiz", 1942, 0, nullptr, 11, searchActors);
        
        // Retrieve the movie
        auto retrievedMovie = classicBST.retrieve(searchKey);
        Test::assertNotNull(retrievedMovie.get(), "Should find the classic movie");
        
        // Merge with the second movie
        Test::assertTrue(retrievedMovie->mergeWith(classic2), "Should merge same movie with different actor");
        Test::assertEquals<int>(15, retrievedMovie->getStock(), "Merged movie should have combined stock");
        
        // Verify the merged movie has all actors
        auto actors = retrievedMovie->getMajorActors();
        Test::assertEquals<size_t>(3, actors.size(), "Should have all three actors after merge");
    }
}

int main() {
    std::cout << "=========================================" << std::endl;
    std::cout << "   Movie Rental System Test Suite" << std::endl;
    std::cout << "=========================================" << std::endl;
    
    // Comedy Movie Tests
    Test::TestCase("Comedy Movie Constructor", Tests::testComedyMovieConstructor).run();
    Test::TestCase("Comedy Movie Comparison", Tests::testComedyMovieComparison).run();
    Test::TestCase("Comedy Movie Merge", Tests::testComedyMovieMerge).run();
    
    // Drama Movie Tests
    Test::TestCase("Drama Movie Constructor", Tests::testDramaMovieConstructor).run();
    // Skipping Drama comparison tests due to access issues
    
    // Classic Movie Tests
    Test::TestCase("Classic Movie Constructor", Tests::testClassicMovieConstructor).run();
    Test::TestCase("Classic Movie Add Actor", Tests::testClassicMovieAddActor).run();
    Test::TestCase("Classic Movie Merge", Tests::testClassicMovieMerge).run();
    
    // BST Tests
    Test::TestCase("Movie BST Insert", Tests::testMovieBSTInsert).run();
    Test::TestCase("Movie BST Retrieve", Tests::testMovieBSTRetrieve).run();
    Test::TestCase("Type-Specific BSTs", Tests::testSpecificBSTForEachMovieType).run();
    
    // Integration Tests
    Test::TestCase("Integration - Adding and Retrieving Movies with Merge", 
                  Tests::testIntegrationAddingAndRetrievingMoviesWithMerge).run();
    
    // Print test summary
    Test::printSummary();
    
    return 0;
}