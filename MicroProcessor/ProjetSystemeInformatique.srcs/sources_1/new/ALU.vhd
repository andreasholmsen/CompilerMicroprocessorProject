library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity ALU is
    Port ( 
        A : in STD_LOGIC_VECTOR (7 downto 0);
        B : in STD_LOGIC_VECTOR (7 downto 0);
		Ctrl_ALU : in STD_LOGIC_VECTOR (2 downto 0);
        S : out STD_LOGIC_VECTOR (7 downto 0);
		C, O, N : out STD_LOGIC -- Carry, Overflow, Negative
		);  
end ALU;

-- https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fimage.slideserve.com%2F284401%2Fcontrol-signals-l.jpg&f=1&nofb=1&ipt=4eb847462bb989b6d03a79982d39887998ee3c1c9b6a9323297a0fa287e83137

-- + - * DIV AND OR XOR NOT
-- 1 2 3 4 5 6 7 8 9 10

architecture Behavioral of ALU is
	signal A_ext, B_ext, S_ext : STD_LOGIC_VECTOR (15 downto 0);
	
begin 

    A_ext <= X"00" & A; 
    B_ext <= X"00" & B;
    -- https://nandland.com/common-vhdl-conversions/
	process (A_ext, B_ext, Ctrl_ALU)
		begin 
			case Ctrl_ALU is
				when "001" => -- PLUS
					S_ext <= STD_LOGIC_VECTOR(unsigned(A_ext) + unsigned(B_ext));
				when "010" => -- MULTIPLICATION
					S_ext <= STD_LOGIC_VECTOR(TO_UNSIGNED(TO_INTEGER(unsigned(A_ext)) * TO_INTEGER(unsigned(B_ext)),16));
				when "011" => -- MINUS
					S_ext <= STD_LOGIC_VECTOR(unsigned(A_ext) - unsigned(B_ext));
				when "100" => -- AND
					S_ext <= X"00" & (A AND B);
				when "101" => -- OR
					S_ext <= X"00" & (A OR B);	
				when "110" => -- XOR
					S_ext <= X"00" & (A XOR B);	
				when "111" => -- NOT A
					S_ext <= X"00" & (NOT A);
				when "000" => -- NOT B
				    S_ext <=  X"00" & (NOT B);
				when others => 
            end case;             
		end process;
		
			S <= S_ext (7 downto 0);
			C <= '1' when (S_ext(15 downto 8)/= X"00" and Ctrl_ALU = "001") else '0';
		    N <= '1' when (B > A and Ctrl_ALU = "011") else '0';
		      
end Behavioral;

-- Add when others
