// class Solution {
// public:
//     int compress(vector<char>& arr) {

//         string s;
//         int count = 1;

//         for(int i = 0; i < arr.size();){
//             char k = arr[i];
//             if(i != arr.size() - 1){
//             i++;
//             }
//             if(arr[i] == k){
//                 count++;
//             }
//             else{
//                 if(count > 1 && count < 10){
//                 s.push_back(arr[i-1]);
//                 s += to_string(count);

//                 count = 1;
//             }
//                 else if(count == 1){
//                     s.push_back(arr[i-1]);
//                     count = 1;
//                 } 
//                 else if(count >= 10){
//                     int num = count/10;
//                     int num2 = count%10;
//                       s.push_back(arr[i-1]);
//                       s += to_string(num);
//                        s += to_string(num2);
//                 }

//             }
//         }

//           arr.assign(s.begin(), s.end());  


//         return arr.size();

//     }
// };


class Solution {
public:
    int compress(vector<char>& arr) {
        int ansIndex = 0;
        int i = 0;
        int n = arr.size();

        while(i < n){
            int j = i + 1;
            while(j < n && arr[i] == arr[j]){
                j++;
            }

            arr[ansIndex++] = arr[i];
            int count = j-i;

            if(count > 1){
                string cnt = to_string(count);
                for( char ch : cnt){
                    arr[ansIndex++] = ch;
                }
            }
            i = j;
        }
        return ansIndex;
    }    
};


     