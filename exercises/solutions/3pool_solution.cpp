binsem worker_sleeping[N]
binsem main_sleeping=0
binsem lock=1
bool working[N]
int to_do[N]
int avail
thread th[N]

main(){
	jobs[] = input()
	
	for(int i=0;i<N;i++){
		thread th[i](worker_thread,i);
		worker_sleeping[i] = 0;
		working[i] = false;
		avail = N
	}
	
	for(int j=0;j<jobs.length;j++){
		down(lock);
		if(avail == 0){
			up(lock);
			down(main_sleeping);
		}
		else
			up(lock);
		
		for(int k=0;k<N;k++){
			if( working[k]==false)
				break
		}
		to_do[k] = jobs[j];
		working[k]=true;
		
		down(lock)
		avail--
		up(lock)
		
		up(worker_sleeping[k]);
		
		
		
		
	}
	
}

worker_thread(int who){
	while(true){
		down(lock)
		
		working[who] = false
		
		avail++
		
		if(avail == 1){
			up(lock)
			up(main_sleeping)
		}
		else{
			up(lock)
		}
		
		down(worker_sleeping[who]);
		
		cout << "Is" << todo[who] <<" a prime?" <<prime_test(todo[who]);
		
		
		
		
		
		
		
		
	}
	
	
}

