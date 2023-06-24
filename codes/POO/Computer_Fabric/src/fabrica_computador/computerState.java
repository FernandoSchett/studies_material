package fabrica_computador;

public interface computerState{
	
	computerState addHd(); 
	computerState addMotherboard();
	computerState addProcessor();
	computerState addMemory();
}
