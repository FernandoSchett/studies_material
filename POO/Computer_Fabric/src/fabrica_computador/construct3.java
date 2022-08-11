package fabrica_computador;

public class construct3 implements computerState {

	@Override
	public computerState addHd() {
		System.out.println("O computador já tem um HD.");
		return this;
	}

	@Override
	public computerState addMotherboard() {
		System.out.println("O computador já tem uma Placa Mãe.");
		return this;
	}

	@Override
	public computerState addProcessor() {
		System.out.println("Processador adicionado com sucesso.");
		return new construct4();
	}

	@Override
	public computerState addMemory() {
		System.out.println("Não se deve adicionar uma memória antes de adicionar um processador.");
		return this;
	}

}
