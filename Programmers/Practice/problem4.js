function solution(weights){
    var answer = 0;

    weights.sort();
    var sum = 0, count = 0;
    var max = 0;
    var biggest = weights[weights.length -1];
    for(var i  = 0; i < weights.length; i++){
        sum+=weights[i];
        count++;
        if(weights[i] != weights[i+1] ){

            // consolel(i)
            // // 찾기
            // console.log('찾기 시작');

            // console.log(`원래 sum: ${sum}`);
            // var t = 2;
            // var newSum = weights[i];
            // while(newSum < sum) {
            //     newSum = weights[i] * t
            //     t *=2;
            // }

            // sum = newSum;

            // console.log(`새로운 sum: ${sum}`);
            var temp = weights[i];
            while(temp <= biggest){
                temp *= 2 ;
                console.log(`찾을 값 : ${temp}`);

                var count = 0;
                for(var j = i+1; j < weights.length; j++){
                    if(weights[j] == temp) count++;
                }

                if(count == sum / temp && max < count){
                    console.log(`저장 : ${count}`);
                    max = count;
                    break;
                }else if(max < sum / weights[i]){
                    max = sum / weights[i];
                }
            }


            sum = 0;
        }
        
    }


    console.log(max);

    return answer;
}

solution([2, 2, 2, 2, 3, 3, 5, 6]);