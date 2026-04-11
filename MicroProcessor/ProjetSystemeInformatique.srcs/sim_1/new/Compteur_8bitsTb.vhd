----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 19.03.2026 23:08:28
-- Design Name: 
-- Module Name: Compteur_8bits - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

entity Compteur_8bitsTb is
end Compteur_8bitsTb;

architecture Sim of Compteur_8bitsTb is
    constant ClockFrequency : integer := 72e6;
    constant ClockPeriod : time := 1000 ms / ClockFrequency;
    
    signal CK : STD_LOGIC := '0';
    signal RST : STD_LOGIC := '1';
    signal LOAD : STD_LOGIC := '0';
    signal SENS : STD_LOGIC := '1';
    signal EN : STD_LOGIC := '1';
    signal Din : STD_LOGIC_VECTOR(7 downto 0) := (others => '0');
    signal Dout : STD_LOGIC_VECTOR(7 downto 0);
begin

    i_Compteur_8bits : entity work.Compteur_8bits(Behavioral) port map(
        CK => CK,
        RST => RST,
        LOAD => LOAD,
        SENS => SENS,
        EN => EN,
        Din => Din,
        Dout => Dout
    );
    
    CK <= not CK after ClockPeriod/2;

    process is
    begin
     -- Test 1, just counting
        EN <= '0';
        wait for 200 ns;
        
        -- Test 2, set value
        Din <= x"DD";
        LOAD <= '1';
        wait for 200 ns;
        
        -- Test 3, decrement
        SENS <= '0';
        LOAD <= '0';
        wait for 200 ns;
        
        
        -- Test 4, reset
        RST <= '0';
        wait for 200ns;
        

        
        
        wait; -- Finish tests
    end process;
    
end architecture;