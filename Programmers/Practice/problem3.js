function solution(reqs){
    var answer = [];
    var accounts = [];

    
    reqs.forEach(element => {
        var temp = element.split(' ');
        var act = temp[0];
        var accountId = temp[1];
        var money = parseInt(temp[2]);


        console.log(temp);

        if(act == 'CREATE'){
            if(accounts.find(element => element.id == accountId) == undefined){
                accounts.push({id: accountId, limit: -money, balance: 0});

                answer.push(200);
            }else{
                answer.push(403);
            }
        }else if(act == 'DEPOSIT'){
            if(accounts.find(element => element.id == accountId) == undefined){
                answer.push(404);
            }else{
                accounts[accounts.findIndex(x => x.id === accountId)].balance += money;

                answer.push(200);
            }
        }else if(act == 'WITHDRAW'){
            if(accounts.find(element => element.id == accountId) == undefined){
                answer.push(404);

            }else{
                var index = accounts.findIndex(x => x.id === accountId);
                if(accounts[index].balance - accounts[index].limit < money){
                    answer.push(403);
                }else{
                    accounts[index].balance = accounts[index].limit - (accounts[index].balance - money);

                    answer.push(200);
                }
            }
        }

        console.log(accounts);
    });

    console.log(`정답:  ${answer}`);

    return answer;
}

solution(["DEPOSIT 3a 10000", "CREATE 3a 300000", "WITHDRAW 3a 150000", "WITHDRAW 3a 150001"]);