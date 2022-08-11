package fabrica_computador;

import java.util.*;

public class computer{
	protected computerState estate;
	
	public computer(){ 
		estate = new emptyComputer();
	}
	
	public void addHd(){
		estate = estate.addHd();
	}
	
	public void addMotherboard(){
		estate = estate.addMotherboard();
	}
	
	public void addProcessor(){
		estate = estate.addProcessor();
	}
	
	public void addMemory(){
		estate = estate.addMemory();
	}
	
}