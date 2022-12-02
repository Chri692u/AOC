const fs = require('fs');
const readline = require('readline');

//partOne()
partTwo()

async function partTwo() {
	//Read input and push to input list
	let input = []
	const fileStream = fs.createReadStream('./inputs/3.txt')
	const rl = readline.createInterface({
		input: fileStream,
		crlfDelay: Infinity
	  })

	for await (const line of rl) {
		input.push(line)	
	}
	
	//Inits
	let carbonRate = recCarbon(0, input)
	let oxygenRate = recOxygen(0, input)

	console.log(carbonRate * oxygenRate)
}

function recOxygen(a, input){
	//Base Case
        if(input.length == 1){
                return parseInt(input,2);
        }

	//Count ones and zeroes
	ones = input.map(x => x[a]).filter(x => x == "1").length
	zeros = input.map(x => x[a]).filter(x => x == "0").length

	//Normalize over ones
	normOnes = ones / (ones + zeros)

	//normOnes > 0.50 = True if 1 is the most common bit, else it is the least
        if(normOnes >= 0.5){
                return recOxygen(a+1, input.filter(x => x[a] == "1"))
        } else {
                return recOxygen(a+1, input.filter(x => x[a] == "0"))
        }

}

function recCarbon(a, input){
	//Base case
        if(input.length == 1){
                return parseInt(input,2);
        }

	//Count ones and zeroes
	ones = input.map(x => x[a]).filter(x => x == "1").length
	zeros = input.map(x => x[a]).filter(x => x == "0").length
	
	//Normalize over ones
	normOnes = ones / (ones + zeros)

	//normOnes > 0.50 = True if 1 is the most common bit, else it is the least
        if(normOnes >= 0.5){
                return recCarbon(a+1, input.filter(x => x[a] == "0"))
        } else {
                return recCarbon(a+1, input.filter(x => x[a] == "1"))
        }

}

async function partOne() {
	//Read input and push to input list
	let input = []
	const fileStream = fs.createReadStream('./inputs/3.txt')
	const rl = readline.createInterface({
		input: fileStream,
		crlfDelay: Infinity
	  })

	for await (const line of rl) {
		input.push(line)	
	}
	
	//Inits
	let limit = input[0].length
	let gammaRate = ""
	let epsilonRate = ""

	for (let i = 0; i < limit; i++){
		//Count ones and zeros
		ones = input.map(x => x[i]).filter(x => x == "1").length
		zeros = input.map(x => x[i]).filter(x => x == "0").length

		//Normalize over ones
		normOnes = ones / (ones + zeros)

		//normOnes > 0.50 = True if 1 is the most common bit, else it is the least
		if (normOnes > 0.50) {
			gammaRate += "1"
                	epsilonRate += "0"
		} else {
			gammaRate += "0"
                	epsilonRate += "1"	
		}
	}

	//Result
	console.log(parseInt(gammaRate,2) * parseInt(epsilonRate, 2))
}
