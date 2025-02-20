#include<iostream>
using namespace std;
class DynamicArray {
	private:
		int* arr;
		size_t arraySize;
	public:
		DynamicArray():arr(nullptr),arraySize(0) {}
		DynamicArray(size_t size):arraySize(size) {
			arr=new int[arraySize]();
		}
		DynamicArray(const DynamicArray& other):arraySize(other.arraySize) {
			arr=new int[arraySize];
			for(size_t i=0; i<arraySize; ++i)arr[i]=other.arr[i];
		}
		DynamicArray(DynamicArray&& other)noexcept:arr(other.arr),arraySize(other.arraySize) {
			other.arr=nullptr;
			other.arraySize=0;
		}
		DynamicArray& operator=(const DynamicArray& other) {
			if(this==&other)return *this;
			delete[] arr;
			arraySize=other.arraySize;
			arr=new int[arraySize];
			for(size_t i=0; i<arraySize; ++i)arr[i]=other.arr[i];
			return *this;
		}
		DynamicArray& operator=(DynamicArray&& other)noexcept {
			if(this!=&other) {
				delete[] arr;
				arr=other.arr;
				arraySize=other.arraySize;
				other.arr=nullptr;
				other.arraySize=0;
			}
			return *this;
		}
		~DynamicArray() {
			delete[] arr;
		}
		size_t size()const {
			return arraySize;
		}
		int& at(int index) {
			return arr[index];
		}
		const int& at(int index)const {
			return arr[index];
		}
		void resize(size_t newSize) {
			if(newSize==arraySize)return;
			int* newArr=new int[newSize]();
			for(size_t i=0; i<min(arraySize,newSize); ++i)newArr[i]=arr[i];
			delete[] arr;
			arr=newArr;
			arraySize=newSize;
		}
};
int main() {
	DynamicArray arr1(5);
	arr1.at(0)=10;
	arr1.at(1)=20;
	DynamicArray arr2=arr1;
	DynamicArray arr3;
	arr3=arr1;
	arr1.resize(10);
	cout<<"Size: "<<arr1.size()<<endl;
	cout<<"Element at index 1: "<<arr1.at(1)<<endl;
	return 0;
}
