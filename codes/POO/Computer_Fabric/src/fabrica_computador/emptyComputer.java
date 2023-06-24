package fabrica_computador;

public class emptyComputer implements computerState{
	
	@Override
	public computerState addHd() {
		System.out.println("HD adicionado no computador com sucesso.");
		return new construct2();
	}

	@Override
	public computerState addMotherboard() {
		System.out.println("Não se deve adicionar uma placa Mãe antes de adicionar um HD.");
		return this;
	}

	@Override
	public computerState addProcessor() {
		System.out.println("Não se deve adicionar um processador antes de adicionar uma Placa Mãe.");
		return this;
	}

	@Override
	public computerState addMemory() {
		System.out.println("Não se deve adicionar uma memória antes de adicionar um Processador.");
		return this;
	}

}
