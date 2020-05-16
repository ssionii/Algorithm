function solution(arr){
    var answer = 1;

    var numArr = Array(arr.length).fill(null).map(()=>Array());
    
   
    arr.forEach(function(element, index) {
        var str = String(element);
        for(var i = 0 ; i < str.length; i++){
            numArr[index].push(parseInt(str[i]));
        }

        numArr[index].sort();
    });

    numArr.sort();

    console.log(numArr);

    for(var i = 0 ; i < numArr.length -1; i++){
        var isSame = true;
        numArr[i+1].forEach(function(element, index){

            console.log(`비교할 값 : ${numArr[i+1][index]}, ${element}`);
            if(element != numArr[i][index]){
                isSame = false;
            }
        })
        console.log(isSame);
        if(!isSame) answer++;

        isSame = true;    
    }

    console.log(answer);
    return answer;
}

solution([112, 1814, 121, 1481, 1184]);