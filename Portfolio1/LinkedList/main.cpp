#include <iostream>
#include <string>
#include "LinkedList.h"

// Represents one mushroom research sample
struct MushroomSample
{
    int sampleId;
    std::string species;
    int daysGrowing;
    double colonizationPercent;
    bool contaminated;

    // Returns true when the sample is ready to fruit
    bool isReadyToFruit() const
    {
        return colonizationPercent >= 100.0 && !contaminated;
    }
};

// Samples are considered equal when their IDs match
bool operator==(const MushroomSample& left,
                const MushroomSample& right)
{
    return left.sampleId == right.sampleId;
}

// Prints the details of one mushroom sample
std::ostream& operator<<(std::ostream& output,
                         const MushroomSample& sample)
{
    output << "Sample " << sample.sampleId
           << ": " << sample.species
           << ", day " << sample.daysGrowing
           << ", " << sample.colonizationPercent << "% colonized"
           << ", contaminated: "
           << (sample.contaminated ? "yes" : "no")
           << ", ready: "
           << (sample.isReadyToFruit() ? "yes" : "no");

    return output;
}

int main()
{
    // Tests the list with integers
    LinkedList<int> numbers;
    numbers.pushFront(5);
    numbers.pushBack(10);
    numbers.pushBack(20);

    std::cout << "Integer list: ";
    numbers.print(std::cout);
    std::cout << "\n\n";

    // Tests the list with strings
    LinkedList<std::string> words;
    words.pushBack("pink");
    words.pushBack("oyster");
    words.pushFront("fungus");

    std::cout << "String list: ";
    words.print(std::cout);
    std::cout << "\n\n";

    // Tests the list with a custom struct
    LinkedList<MushroomSample> samples;

    samples.pushBack({101, "Pink Oyster", 12, 100.0, false});
    samples.pushBack({102, "Lion's Mane", 9, 76.5, false});
    samples.pushBack({103, "Shiitake", 18, 92.0, true});

    std::cout << "Mushroom samples:\n";

    // Uses the custom forward iterator
    for (const MushroomSample& sample : samples)
    {
        std::cout << "  " << sample << '\n';
    }

    // Tests searching with the custom struct
    MushroomSample searchSample = {102, "", 0, 0.0, false};

    std::cout << "\nContains sample 102: "
              << samples.contains(searchSample) << '\n';

    // Tests that a copied list has separate nodes
    LinkedList<MushroomSample> copiedSamples = samples;
    copiedSamples.remove(searchSample);

    std::cout << "Original size: " << samples.size() << '\n';
    std::cout << "Copied size after removal: "
              << copiedSamples.size() << '\n';

    return 0;
}
