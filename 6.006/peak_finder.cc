#include <iostream>
#include <vector>

int peak_finder_binary(std::vector<int> numbers)
{
    int left = 0, right = numbers.size() - 1;

    while(right > left) {
        int mid = (right + left) / 2;
        std::cout << "Left: " << left << ", Right: " << right << std::endl;
        
        if(mid - 1 >= left) {
            if(numbers[mid - 1] <= numbers[mid] && numbers[mid] >= numbers[mid + 1])
                return mid;
            else if(numbers[mid - 1] >= numbers[mid])
                right = mid - 1;
            else if(numbers[mid + 1] >= numbers[mid])
                left = mid + 1;
        } else {
            if(numbers[mid + 1] >= numbers[mid])
                return mid + 1;
            else
                return mid;
        }
    }

    return right;
}

int main()
{
    int i;
    std::vector<int> numbers;

    std::cout << "Enter numbers: ";
    while(std::cin >> i)
        numbers.push_back(i);
    std::cout << "\n\n";
    
    std::cout << "Index " << peak_finder_binary(numbers) << " is the peak of this vector." << std::endl;

    return 0;
}