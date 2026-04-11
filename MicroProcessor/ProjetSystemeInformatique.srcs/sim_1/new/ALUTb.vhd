library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ALUTb is
end ALUTb;

architecture Sim of ALUTb is
        signal A : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');
        signal B : STD_LOGIC_VECTOR (7 downto 0) := (others => '0');
		signal Ctrl_ALU : STD_LOGIC_VECTOR (2 downto 0);
        signal S : STD_LOGIC_VECTOR (7 downto 0);
		signal C, O, N : STD_LOGIC := '0';
begin
    i_ALUTb : entity work.ALU(Behavioral) port map(
        A => A,
        B => B,
        Ctrl_ALU => Ctrl_ALU,
        S => S,
        C => C, 
        O => O,
        N => N
    );
    
    process is
    begin
        -- Test1, addition
        Ctrl_ALU <= "001";
        A <= X"02";
        B <= X"02";
        
        wait for 50ns;
        A <= X"04";
        wait for 50ns;
        A <= X"AA";
        
        wait for 100ns;
        
        
        --Test2, negative number substraction
        
        A <= X"01";
        Ctrl_ALU <= "011";
        
        wait for 100ns;
        
        -- Test3 multiplication
        
         A <= X"06";
         B <= X"05";
        Ctrl_ALU <= "010";
        wait for 50ns;
         A <= X"03";
         B <= X"02";
        Ctrl_ALU <= "010";
        wait for 100ns;
        
        --Test 4 AND OR XOR NOT(A)
        
        Ctrl_ALU <= "100";
        wait for 50ns;
        Ctrl_ALU <= "101";
        wait for 50ns;
        Ctrl_ALU <= "110";
        wait for 50ns;
        Ctrl_ALU <= "111";
        wait for 50ns;
        
        wait;
    end process;
end architecture;
