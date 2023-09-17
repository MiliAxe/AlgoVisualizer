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

class QuickSort : public SortAlgorithm {
public:
    QuickSort(Sorter *sortPtr);

    void sort(App &app) override;

    int partition(std::vector<Bar> &values, int left, int right, App &app);

    void quickSort(std::vector<Bar> &values, int left, int right, App &app);
};
