function solution(arr){
    var answer = 0;
    
    var newArr = [];
    var count = 1;

    while(arr.length != 1 || arr[0] != 1){

        for(var i = 0 ; i < arr.length-1; i++){
            if(arr[i] == arr[i+1]){
                count++;
            }else{
                newArr.push(count);
                count = 1;
            }
        }
        newArr.push(count);
        arr = newArr;
        newArr = [];
        count = 1;

        answer++;

    }

    return answer;
}
