monitor barber_shop{
	int free_chairs = N;
	condition customers,barber;
	
	
	
	give_haircut(){
		if(free_chairs == N)
			wait(customers);
		free_chairs++;
		signal(barber);
		//cut hair
		
	}
	
	
	get_haircut{
		if(free_chairs!=0){
			free_chairs--;
			if(free_chairs == N-1)
				signal(customers);
			wait(barber);
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


