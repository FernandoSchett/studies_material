package fabrica_computador;

public class construct2 implements computerState {

	@Override
	public computerState addHd() {
		System.out.println("O computador já tem um HD.");
		return this;
	}

	@Override
	public computerState addMotherboard() {
		System.out.println("Placa Mãe adicionada com sucesso.");
		return new construct3();
	}

	@Override
	public computerState addProcessor() {
		System.out.println("Não se deve adicionar um processador antes de adicionar uma Placa Mãe.");
		return this;
	}

	@Override
	public computerState addMemory() {
		System.out.println("Não se deve adicionar uma memória antes de adicionar um processador");
		return this;
	}

}
