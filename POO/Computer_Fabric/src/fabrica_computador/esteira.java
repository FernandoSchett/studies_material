package fabrica_computador;

public class esteira {
	public static void main(String[] args){
		computer computador = new computer();
		computador.addHd();
		computador.addHd();
		computador.addMotherboard();
		computador.addProcessor();
		computador.addMemory();
	}
}
