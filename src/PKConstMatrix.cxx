#include "PKConstMatrix.hxx"

PKCompMatrix Pauli(int label)
{
	PKCompMatrix temp;
	PKLogger _pauli_log = PKLogger( "PKCONSTMATRIX" );
	
	switch(label)
	{
		case 1:
			temp.addRow(PKComplexVar(1,0), PKComplexVar(0,0));
			temp.addRow(PKComplexVar(0,0), PKComplexVar(1,0));
			break;
		case 2:
			temp.addRow(PKComplexVar(0,0), PKComplexVar(0,-1));
			temp.addRow(PKComplexVar(0,1), PKComplexVar(0,0));
			break;
		case 3:
			temp.addRow(PKComplexVar(1,0), PKComplexVar(0,0));
			temp.addRow(PKComplexVar(0,0), PKComplexVar(-1,0));
			break;
		default:
			_pauli_log.Error( "Invalid Option for Constant Matrix 'Pauli', state 1, 2, 3 for x, y, z" );
			exit(EXIT_FAILURE);
	}

	return temp;
}

PKCompMatrix Dirac(int label)
{
	PKCompMatrix temp;
	PKLogger _dirac_log = PKLogger( "PKCONSTMATRIX" );
	
	switch(label)
	{
		case 0:
			temp.addRow(PKComplexVar(1,0), PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,0));
			temp.addRow(PKComplexVar(0,0), PKComplexVar(1,0), PKComplexVar(0,0), PKComplexVar(0,0));
			temp.addRow(PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(-1,0), PKComplexVar(0,0));
			temp.addRow(PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(-1,0));
			break;

		case 1:
			temp.addRow(PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(1,0));
			temp.addRow(PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(1,0), PKComplexVar(0,0));
			temp.addRow(PKComplexVar(0,0), PKComplexVar(-1,0), PKComplexVar(0,0), PKComplexVar(0,0));
			temp.addRow(PKComplexVar(-1,0), PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,0));
			break;
		case 2:
			temp.addRow(PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,-1));	
			temp.addRow(PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,1), PKComplexVar(0,0));
			temp.addRow(PKComplexVar(0,0), PKComplexVar(0,1), PKComplexVar(0,0), PKComplexVar(0,0));
			temp.addRow(PKComplexVar(0,-1), PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,0));
			break;
		case 3:
				
			temp.addRow(PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(1,0), PKComplexVar(0,0));
			temp.addRow(PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(-1,0));
			temp.addRow(PKComplexVar(-1,0), PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,0));
			temp.addRow(PKComplexVar(0,0), PKComplexVar(1,0), PKComplexVar(0,0), PKComplexVar(0,0)); 
			break;
		case 5:
			temp.addRow(PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(1,0), PKComplexVar(0,0));
			temp.addRow(PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(1,0));
			temp.addRow(PKComplexVar(1,0), PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,0));
			temp.addRow(PKComplexVar(0,0), PKComplexVar(1,0), PKComplexVar(0,0), PKComplexVar(0,0)); 
			break;
		default:
			_dirac_log.Error( "Invalid option for PKConst Matrix 'Dirac', argument must be 0, 1, 2, 3 or 5" );
			exit(EXIT_FAILURE);
	}
	
	return temp;

}

PKCompMatrix alpha(int label)
{
	return Dirac(label);
}

PKCompMatrix beta()
{
	return Dirac(0);
}

PKCompMatrix g()
{
	PKCompMatrix temp;
	temp.addRow(PKComplexVar(1,0), PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,0));
	temp.addRow(PKComplexVar(0,0), PKComplexVar(-1,0), PKComplexVar(0,0), PKComplexVar(0,0));
	temp.addRow(PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(-1,0), PKComplexVar(0,0));
	temp.addRow(PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(0,0), PKComplexVar(-1,0));

	return temp;
}

PKCompMatrix I(int label)
{
	std::vector<std::vector<PKComplexVar>> _rows;
	for(int i{0}; i<label; ++i)
	{
		std::vector<PKComplexVar> _row;
		for(int j{0}; j<label; ++j)
		{
			if(j==i){_row.push_back( PKComplexVar(1,0) );}
			else{_row.push_back( PKComplexVar(0,0) );}
		}
		
		_rows.push_back(_row);
	}

	PKCompMatrix _temp(_rows);

	return _temp;

}
