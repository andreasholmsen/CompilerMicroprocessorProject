library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

entity Banc_RegistreTb is
end Banc_RegistreTb;

architecture Sim of Banc_RegistreTb is
    constant ClockFrequency : integer := 72e6;
    constant ClockPeriod : time := 1000 ms / ClockFrequency;
    
    signal ADDR_A : STD_LOGIC_VECTOR(3 downto 0) := (others => '0');
    signal QA : STD_LOGIC_VECTOR(7 downto 0);

    signal ADDR_B : STD_LOGIC_VECTOR(3 downto 0) := (others => '0');
    signal QB : STD_LOGIC_VECTOR(7 downto 0);

    signal ADDR_W : STD_LOGIC_VECTOR(3 downto 0) := (others => '0');
    signal DATA   : STD_LOGIC_VECTOR(7 downto 0) := (others => '0') ;
    signal W      : STD_LOGIC := '0';

    signal RST    :  STD_LOGIC := '0';
    signal CLK    : STD_LOGIC := '0';
begin

    i_Banc_Registre : entity work.Banc_Registre(Behavioral) port map(
        ADDR_A => ADDR_A,
        QA => QA,
        ADDR_B => ADDR_B,
        QB=>QB,
        ADDR_W => ADDR_W,
        DATA => DATA,
        W => W,
        RST => RST,
        CLK => CLK
    );
    
    CLK <= not CLK after ClockPeriod/2;

    process is
    begin
        --Test 1, reset
        RST <= '1';
        
        wait for 100ns;
        
        -- Test 2, assigning values and display
        RST <= '0';
        
        ADDR_W <= "0011";
        DATA <= "11001100";
        W <= '1';
        wait for 50ns;
        W <= '0';
        wait for 50ns;
        ADDR_W <= "1100";
        DATA <= "00110011";
        W <= '1';
        wait for 50ns;
        W <= '0';
        wait for 50ns;
        
        ADDR_B <= "0011"; -- QB = X"CC"
        ADDR_A <= "1100"; -- QA = X"33"
        
        wait for 100ns;
        
        
        -- Test 3, new reset
        RST <= '1';        
        
        wait; -- Finish tests
    end process;
    
end architecture;