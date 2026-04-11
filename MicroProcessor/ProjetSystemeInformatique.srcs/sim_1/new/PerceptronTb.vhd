----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 20.03.2026 00:11:10
-- Design Name: 
-- Module Name: PerceptronTb - Sim
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
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity PerceptronTb is
--  Port ( );
end PerceptronTb;

architecture Sim of PerceptronTb is
    constant ClockFrequency : integer := 72e6;
    constant ClockPeriod : time := 1000 ms / ClockFrequency;

    signal Clock       : STD_LOGIC := '0';
    signal Reset       : STD_LOGIC := '1';
    signal Enable      : STD_LOGIC := '0';
    signal Input_Value : STD_LOGIC_VECTOR(31 downto 0) := (others => '0');
    signal Output_Value: STD_LOGIC_VECTOR(31 downto 0);
    signal Valid       : STD_LOGIC;

    
begin
    i_Perceptron: entity work.Perceptron Port map (
            Clock => Clock,
            Reset => Reset,
            Enable => Enable,
            Input_Value => Input_Value,
            Output_Value => Output_Value,
            Valid => Valid
        );
    
     Clock <= not Clock after ClockPeriod/2;

    process is
    begin
    
         -- Test 1
        Enable <= '1';
        Input_Value <= X"12345678";
        wait for 1000 ns;
        Enable <= '0';
        wait for 1000 ns;
        
        -- Test 2 - reset
        Reset <= '0';
        wait for 1000 ns;
        Reset <= '1';
        wait for 1000 ns;

       

        -- Test 3
        Input_Value <= X"00000001";
        Enable <= '1';
        wait for 10 ns;
        Enable <= '0';
        wait for 1000 ns;

        -- Test 4
        Input_Value <= X"FFFFFFFF";
        Enable <= '1';
        wait for 10 ns;
        Enable <= '0';
        wait;
    end process;
end Sim;
