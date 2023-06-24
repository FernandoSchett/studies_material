package fabrica_computador;

public class completeComputer implements computerState {

	@Override
	public computerState addHd() {
		System.out.println("O computador está completo.");
		return null;
	}

	@Override
	public computerState addMotherboard() {
		System.out.println("O computador está completo.");
		return null;
	}

	@Override
	public computerState addProcessor() {
		System.out.println("O computador está completo.");
		return null;
	}

	@Override
	public computerState addMemory() {
		System.out.println("O computador está completo.");
		return null;
	}

}
