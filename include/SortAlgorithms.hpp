#include <Sorter.hpp>
#include <App.hpp>
#include <vector>


class SortAlgorithm {
protected:
    Sorter *sorterPtr;

public:
    virtual void sort(App &app) = 0;
};

class BubbleSort : public SortAlgorithm {
public:
    BubbleSort(Sorter *sortPtr);

    void sort(App &app) override;
};