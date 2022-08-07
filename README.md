The Set class will have three private data members: 
1. An array to store the elements of the sets. 
2. An integer value to store the capacity of the array which can be determined when creating a new set object. The default value is 10 if the capacity is not specified.
3. An integer value to store the number of items in the array.

You first need to implement the constructor, copy constructor and destructor for the Set class, and then the following two member functions.
### 1. addElement 
Add an element to the set object. If the element is already in the set object, then DO NOT add it.
### 2. removeElement 
Return false only if the element is not in the set object. Otherwise, remove that element from the set object and then return true.
___
 
Let us define the sets we are considering as left set and right set for simplicity. You will need to  overload the following operators: 
### 1. operator+ 
Return the union of the left set and the right set. 
### 2. operator- 
Return the difference of the left set from the right set.
### 3. operator== 
Compare the two sets and return true if they are the  same. Otherwise, return false. Note that two sets are equal if every element of one set is also the element of the other regardless of the internal order of elements in their representation. 
### 4. operator!= 
Compare the two sets and return true if they are not the same. Otherwise, return false. 
### 5. operator= 
Copy the contents of the right set to the left set. After this operation, both sets should have only the elements of the right set. 
### 6. operator+= 
Perform the union of two sets and store the result in set which is at the left hand side of the equality. Also return the union of the two sets. 
### 7. operator< 
Return true only if the set on the left is a subset of the set on the right. Otherwise, return false.
### 8. operator<< 
Output the contents of the set. 
### 9. operator>> 
Fill in the empty places in the set so that the number of elements in the set is equal to the capacity of the set.