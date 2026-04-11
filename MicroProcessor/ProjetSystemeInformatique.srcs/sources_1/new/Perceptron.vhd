----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 19.03.2026 23:44:35
-- Design Name: 
-- Module Name: Perceptron - Behavioral
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
use IEEE.NUMERIC_STD.ALL;

entity Perceptron is
    Port ( Clock : in STD_LOGIC;
           Reset : in STD_LOGIC;
           Enable : in STD_LOGIC;
           Input_Value : in STD_LOGIC_VECTOR (31 downto 0);
           Output_Value : out STD_LOGIC_VECTOR (31 downto 0);
           Valid : out STD_LOGIC);
end Perceptron;

architecture Behavioral of Perceptron is
    constant N : integer := 10; -- From config file
    
    -- Instanciation from config file
    type t_Weights_Bias is array (N Downto 0) of STD_LOGIC_VECTOR(31 downto 0);
    signal Weights_Bias : t_Weights_Bias;
    
    signal Valid_t : STD_LOGIC;
    signal Output_Value_t : STD_LOGIC_VECTOR(63 downto 0);
    
   
begin
    process(Clock) is
        variable i : integer := 0;
    begin
        if rising_edge(Clock) then
            if Reset='0' then
            Output_Value_t <= (others => '0');
            Valid_t <= '0';
            i := 0;
            else
                if Enable='1' then
                --First iteration
                    Output_Value_t <= STD_LOGIC_VECTOR(signed(Weights_Bias(N))+signed(Input_Value)*Signed(Weights_Bias(N-1)));
                    i := 1;
                    Valid_t <= '0';
                elsif Valid_t = '0' and i /= 0 then
                    --Iterations
                    Output_Value_t <= STD_LOGIC_VECTOR(signed(Output_Value_t)+signed(Input_Value)*Signed(Weights_Bias(N-i)));
                    i := i+1;
                    if N-i = 1 then
                        -- Last iteration
                        Valid_t <= '1';
                    end if;
                end if;    
            end if;   
        end if; 
    end process;    

    Valid <= Valid_t;
    
    process (Output_Value_t)
    begin
        report "test";
    
    --ReLu
    -- case Output_Value_t(47) is
    --      when '1' => 
    --          Output_Value <= (others => '0');
    --      when others =>
    --          Output_Value <= Output_Value_t(47 downto 16);
    -- end case;
    
    -- hardtan
        if (Output_Value_t(47 downto 32)=X"0000" or Output_Value_t(47 downto 32) = X"FFFF") then
            Output_Value <= Output_Value_t(47 downto 16);
        elsif Output_Value_t(47)='1' then
            Output_Value <= X"FFFF0000";
        end if;
    end process;
end Behavioral;
