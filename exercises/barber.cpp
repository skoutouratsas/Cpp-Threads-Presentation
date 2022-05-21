monitor barber_shop{
	int free_chairs = N;
	condition customers,barber;
	
	
	
	give_haircut(){
		if(...)			//barbershop is empty
			...			//sleep
		free_chairs++;
		...				//take the customer for a haircut
		//cut hair
		
	}
	
	
	get_haircut{
		if(free_chairs!=0){
			free_chairs--;
			if(...)			//i'm the first to enter
				...			//wake the barber up!
			...				//sit in a chair and wait
			//get_haircut
		}
		else{
			//leave
		}
		
	}
	
	
	
	
	
	
	
}


barber:

	while(true){
		barber_shop.give_haircut();
	}
	
customer:
	barber_shop.get_haircut();


