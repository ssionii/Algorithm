function solution(answers) {
    var answer = [];

    var pattern1 = [1, 2, 3, 4, 5];
    var pattern2 = [2, 1, 2, 3, 2, 4, 2, 5];
    var pattern3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];

    var count = [
        {num : 1, count: 0},
        {num : 2, count: 0},
        {num : 3, count: 0}
    ];

    
    for(var i = 0 ; i < answers.length; i++){
        if(pattern1[i % pattern1.length] == answers[i]) count[0].count++;
        if(pattern2[i % pattern2.length] == answers[i]) count[1].count++;
        if(pattern3[i % pattern3.length] == answers[i]) count[2].count++;
    }

    count.sort(function (a, b){
        if(a.count == b.count)
            return a.num < b.num;
        return a.count > b.count 
    });

    if(count[0].count > count[1].count){
        answer = [count[0].num];
    }else if(count[0].count == count[1].count){
        answer = [count[0].num, count[1].num];
    }else if(count[0].count == count[1].count == count[2].count){
        answer = [count[0].num, count[1].num, count[2].num];
    }


    return answer;
}

console.log(solution([1, 2, 3, 4, 5,]));