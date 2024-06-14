#include <stdio.h>
#include <stdlib.h>
/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 ----------------------

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

------------------

 * Note: The returned array must be malloced, assume caller calls free().
 */

/* ZAMAN KARMAŞILIĞI = O(n^2)
   ALAN KARMAŞIKLIĞI = O(n) ?
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // yeni bir dizi için yer açıldı 2 tane integer boyutuna sahip bellek alanı dizi olarak ayrıldı.
int* returnArray = (int*)malloc(2 * sizeof(int));
//döndürülecek dizi boyutunu belirtmeyi sağlar
*returnSize =2;
    int i,j;
    // parametre olarak alanan dizi boyutu kullanılarak dizi dolaşılıyor
    for(i=0; i < numsSize; i++){
        // dizi içinde ikili olarak karşılaştırma yapabilmek için j değeri i+1 den başlatılır.
        for(j=1; j < numsSize; j++){
            // her i ve j ikililerinin toplamları hedef sayıya eşit mi diye kontrol edilir. 
            if(nums[i] + nums[j] == target){
                // eşitlerse ayırdığımız diziye değerleri atayarak elemanların indexi belirlenmiş olur
                returnArray[0] = i;
                returnArray[1] = j;
                // dizi döndürülür
                return returnArray;
            }
            
        }
    } 

// ayrılan alan boşaltılır
free(returnArray);
return NULL;

}

int main(){
    //fonksiyonda kullanabilmek için parametreler hazırlanır
    int nums[] = {2,7,11,15};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 9;
    // returnsize farklı senaryolar için esneklik sağlar 
    // şuanki kodumuzda 2 sayı toplanacağı belli olduğundan olup olmaması çok da önemli değil

    int* returnSize;
    // fonksiyon çağrılır ve sonucu bir değişkene atanıp yazdırılır
    int* result = twoSum(nums, numsSize, target, returnSize);
    printf("%d %d\n", result[0], result[1]);



    return 0;
}