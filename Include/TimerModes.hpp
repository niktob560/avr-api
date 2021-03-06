#pragma once

#define _TIMER_MODES


/*				T/C0 Compare Output Mode, non-PWM Mode
 *	COM0A1		COM0A0		Desc
 *	0			0			Normal port operation, OC0A disconnected.
 *	0			1			Toggle OC0A on Compare Match
 *	1			0			Clear OC0A on Compare Match
 *	1			1			Set OC0A on Compare Match
 */

#define TIMER0_COMA_NPWM_NORMAL		((0 << COM0A1) | (0 << COM0A0))
#define TIMER0_COMA_NPWM_TOGGLE		((0 << COM0A1) | (1 << COM0A0))
#define TIMER0_COMA_NPWM_CLEAR		((1 << COM0A1) | (0 << COM0A0))
#define TIMER0_COMA_NPWM_SET		((1 << COM0A1) | (1 << COM0A0))

/*				T/C0 Compare Output Mode, Fast PWM Mode
 *	COM0A1		COM0A0		Desc
 *	0			0			Normal port operation, OC0A disconnected.
 *	0			1			WGM02 = 0: Normal Port Operation, OC0A Disconnected.
 *							WGM02 = 1: Toggle OC0A on Compare Match.
 *	1			0			Clear OC0A on Compare Match, set OC0A at TOP
 *	1			1			Set OC0A on Compare Match, clear OC0A at TOP
 */

#define TIMER0_COMA_FPWM_NORMAL			((0 << COM0A1) | (0 << COM0A0))
#define TIMER0_COMA_FPWM_WGM_SET		((0 << COM0A1) | (1 << COM0A0))
#define TIMER0_COMA_FPWM_CM_ST			((1 << COM0A1) | (0 << COM0A0))
#define TIMER0_COMA_FPWM_SM_CT			((1 << COM0A1) | (1 << COM0A0))

/*				T/C0 Compare Output Mode, Phase Correct PWM Mode
 *	COM0A1		COM0A0		Desc
 *	0			0			Normal port operation, OC0A disconnected
 *	0			1			WGM02 = 0: Normal Port Operation, OC0A Disconnected.
 *							WGM02 = 1: Toggle OC0A on Compare Match
 *	1			0			Clear OC0A on Compare Match when up-counting. Set OC0A on
 * 							Compare Match when down-counting.
 *	1			1			Set OC0A on Compare Match when up-counting. Clear OC0A on
 * 							Compare Match when down-counting.
 */

#define TIMER0_COMA_PWM_PHC_NORMAL		((0 << COM0A1) | (0 << COM0A0))
#define TIMER0_COMA_PWM_PHC_WGM_SET		((0 << COM0A1) | (1 << COM0A0))
#define TIMER0_COMA_PWM_PHC_CMUC_SMDC	((1 << COM0A1) | (0 << COM0A0))
#define TIMER0_COMA_PWM_PHC_SMUC_SMDC	((1 << COM0A1) | (1 << COM0A0))

/*				T/C0 Compare Output Mode, non-PWM Mode
 *	COM0B1 		COM0B0		Desc
 *	0			0			Normal port operation, OC0B disconnected.
 *	0			1			Toggle OC0B on Compare Match
 *	1			0			Clear OC0B on Compare Match
 *	1			1			Set OC0B on Compare Match
 */

#define TIMER0_COMB_NPWM_NORMAL		((0 << COM0B1) | (0 << COM0B0))
#define TIMER0_COMB_NPWM_TOGGLE		((0 << COM0B1) | (1 << COM0B0))
#define TIMER0_COMB_NPWM_CLEAR		((1 << COM0B1) | (0 << COM0B0))
#define TIMER0_COMB_NPWM_SET		((1 << COM0B1) | (1 << COM0B0))


/*				T/C0 Compare Output Mode, Fast PWM Mode
 *	COM0B1		COM0B0		Desc
 *	0			0			Normal port operation, OC0B disconnected.
 *	0			1			Reserved
 *	1			0			Clear OC0B on Compare Match, set OC0B at TOP
 *	1			1			Set OC0B on Compare Match, clear OC0B at TOP
 */

#define TIMER0_COMB_FPWM_NORMAL		((0 << COM0B1) | (0 << COM0B0))
#define TIMER0_COMB_FPWM_CM_ST		((1 << COM0B1) | (0 << COM0B0))
#define TIMER0_COMB_FPWM_SM_CT		((1 << COM0B1) | (1 << COM0B0))

/*				T/C0 Compare Output Mode, Phase Correct PWM Mode
 *	COM0B1		COM0B0		Desc
 *	0			0			Normal port operation, OC0B disconnected.
 *	0			1			Reserved
 *	1			0			Clear OC0B on Compare Match when up-counting. Set OC0B on
 *							Compare Match when down-counting.
 *	1			1			Set OC0B on Compare Match when up-counting. Clear OC0B on
 *							Compare Match when down-counting.
 */

#define TIMER0_COMB_PWM_PHC_NORMAL		((0 << COM0B1) | (0 << COM0B0))
#define TIMER0_COMB_PWM_PHC_CMUC_SMDC	((1 << COM0B1) | (0 << COM0B0))
#define TIMER0_COMB_PWM_PHC_SMUC_CMDC	((1 << COM0B1) | (1 << COM0B0))

/*				T/C0 Waveform Generation Mode Bit Description
 *	Mode 	WGM02 	WGM01 	WGM00		T/C mode of operation 	TOP  		Update of OCRx at	TOV flag set on
 *	0		0		0		0			Normal 					0xFF 		Immediate 			MAX
 *	1		0		0		1			PWM PHC 				0XFF 		TOP 				BOTTOM
 *	2		0		1		0			CTC 					OCR0A 		Immediate 			MAX
 *	3		0		1		1			FPWM 					0XFF 		TOP 				MAX
 *	4		1		0		0			Reserved 				-- 			-- 					--
 *	5		1		0		1			PWM PHC 				OCR0A 		TOP 				BOTTOM
 *	6		1		1		0			Reserved 				-- 			-- 					--
 *	7		1		1		1			FPWM 					OCR0A 		TOP 				TOP
 */

#define TIMER0_WF_NORMAL 				((0 << WGM02) | (0 << WGM01) | (0 << WGM00))
#define TIMER0_WF_PWM_PHC 				((0 << WGM02) | (0 << WGM01) | (1 << WGM00))
#define TIMER0_WF_CTC	 				((0 << WGM02) | (1 << WGM01) | (0 << WGM00))
#define TIMER0_WF_FPWM	 				((0 << WGM02) | (1 << WGM01) | (1 << WGM00))
#define TIMER0_WF_PWM_PHC_TOPOCR0A		((1 << WGM02) | (0 << WGM01) | (1 << WGM00))
#define TIMER0_WF_FPWM_TOPOCR0A			((1 << WGM02) | (1 << WGM01) | (1 << WGM00))

/*				T/C0 Clock Select Bit Description 
 *	CS02 	CS01 	CS00 	Desc
 *	0		0		0		No CLK
 *	0		0		1		clk/1
 *	0		1		0		clk/8
 *	0		1		1		clk/64
 *	1		0		0		clk/256
 *	1		0		1		clk/1024
 *	1		1		0		EXT T0 falling
 *	1		1		1		EXT T0 rising
 */

#define TIMER0_CLK_SRC_NO				((0 << CS02) | (0 << CS01) | (0 << CS00))
#define TIMER0_CLK_SRC_1				((0 << CS02) | (0 << CS01) | (1 << CS00))
#define TIMER0_CLK_SRC_8				((0 << CS02) | (1 << CS01) | (0 << CS00))
#define TIMER0_CLK_SRC_64				((0 << CS02) | (1 << CS01) | (1 << CS00))
#define TIMER0_CLK_SRC_256				((1 << CS02) | (0 << CS01) | (0 << CS00))
#define TIMER0_CLK_SRC_1024				((1 << CS02) | (0 << CS01) | (1 << CS00))
#define TIMER0_CLK_SRC_EXT_FALLING		((1 << CS02) | (1 << CS01) | (0 << CS00))
#define TIMER0_CLK_SRC_EXT_RISING		((1 << CS02) | (1 << CS01) | (1 << CS00))
#define TIMER0_CLK_SRC_MASK				((1 << CS02) | (1 << CS01) | (1 << CS00))

/*
 * 													TIMER/COUNTER 2 waveform Description
 * Mode 	WGM2	WGM1 	WGM0 	Timer/Counter Mode of Operation		TOP 	Update of OCRx at 	TOV Flag Set on
 * 0		0		0		0		Normal							0xFF 		Immediate 			MAX
 * 1		0		0		1		PWM, Phase correct				0xFF 		TOP					BOTTOM
 * 2		0		1		0		CTC								OCRA		Immediate			MAX
 * 3		0		1		1		Fast PWM						0xFF 		TOP					MAX
 * 4		1		0		0		Reserved						----		----				----
 * 5		1		0		1		PWM, Phase correct 				OCRA		TOP					BOTTOM
 * 6		1		1		0		Reserved						----		----				----
 * 7		1		1		1		Fast PWM						OCRA		TOP					TOP
 */

#define TIMER2_WF_NORMAL 			((0 << WGM22) | (0 << WGM21) | (0 << WGM20))
#define TIMER2_WF_PWM_PHC 			((0 << WGM22) | (0 << WGM21) | (1 << WGM20))
#define TIMER2_WF_CTC 				((0 << WGM22) | (1 << WGM21) | (0 << WGM20))
#define TIMER2_WF_FPWM 				((0 << WGM22) | (1 << WGM21) | (1 << WGM20))
#define TIMER2_WF_PWM_PHC_TOPOCRA	((1 << WGM22) | (1 << WGM21) | (0 << WGM20))
#define TIMER2_WF_FPWM_TOPOCRA		((1 << WGM22) | (1 << WGM21) | (1 << WGM20))
#define TIMER2_WF_MASK				((1 << WGM22) | (1 << WGM21) | (1 << WGM20))

/*
 * 												T/C2	Compate Output Mode, non-PWM
 * COM2A1		COM2A0		Description
 * 0			0 			Normal port orientation, OC0A disconnected
 *
 * 0 			1			Toggle OC2A on Compare Match
 *
 * 1 			0			Clear OC2A on Compare Match
 *
 * 1 			1			Set OC2A on Compare Match
 */

#define TIMER2_COMA_NORMAL				((0 << COM2A1) | (0 << COM2A1))
#define TIMER2_COMA_WGM_SET				((0 << COM2A1) | (1 << COM2A1))
#define TIMER2_COMA_CM_ST				((1 << COM2A1) | (0 << COM2A1))
#define TIMER2_COMA_SM_CT				((0 << COM2A1) | (0 << COM2A1))
#define TIMER2_COMA_MASK				((1 << COM2A1) | (1 << COM2A0))

/*
 * 											T/C2	Compare Output Mode, Fast PWM Mode
 * COM2A1		COM2A0		Description
 * 0			0			Normal port operation, OC2A disconnected
 *
 * 0			1			WGM22 = 0: Normal Port Operation, OC0A Disconnected.
 * 							WGM22 = 1: Toggle OC2A on Compare Match.
 *
 * 1			0			Clear OC2A on Compare Match, set OC2A at TOP
 *
 * 1			1			Set OC2A on Compare Match, clear OC2A at TOP
 */


/*
 * 											T/C2	Compare Output Mode, Phase Correct PWM Mode
 * COM2A1		COM2A0		Description
 * 0			0			Normal port operation, OC2A disconnected.
 *
 * 0			1			WGM22 = 0: Normal Port Operation, OC2A Disconnected.
 *
 * 							WGM22 = 1: Toggle OC2A on Compare Match
 *
 * 1			0			Clear OC2A on Compare Match when up-counting. Set OC2A on Compare Match when down-counting.
 *
 * 1			1			Set OC2A on Compare Match when up-counting. Clear OC2A on Compare Match when down-counting.
 */

#define TIMER2_COMA_PWM_PHC_NORMAL		((0 << COM2A1) | (0 << COM2A0))
#define TIMER2_COMA_PWM_PHC_WGM_SET		((0 << COM2A1) | (1 << COM2A0))
#define TIMER2_COMA_PWM_PHC_CMUC_SMDC	((1 << COM2A1) | (0 << COM2A0))
#define TIMER2_COMA_PWM_PHC_SMUC_CMDC	((1 << COM2A1) | (1 << COM2A0))

/*
 * 												T/C2	Compate Output Mode, non-PWM
 * COM2B1		COM2B0		Description
 * 0			0 			Normal port orientation, OC0B disconnected
 *
 * 0 			1			Toggle OC2B on Compare Match
 *
 * 1 			0			Clear OC2B on Compare Match
 *
 * 1 			1			Set OC2B on Compare Match
 */
/*
 * 											T/C2	Compare Output Mode, Fast PWM Mode
 * COM2B1		COM2B0		Description
 * 0			0			Normal port operation, OC2B disconnected
 * 
 * 0			1			Reserved
 * 
 * 1			0			Clear OC2B on Compare Match, set OC2B at TOP
 * 
 * 1			1			Set OC2B on Compare Match, clear OC2B at TOP
 */


#define TIMER2_COMB_NORMAL			((0 << COM2B1) | (0 << COM2B0))
#define TIMER2_COMB_TOGGLE			((0 << COM2B1) | (1 << COM2B0))
#define TIMER2_COMB_CM_ST			((1 << COM2B1) | (0 << COM2B1))
#define TIMER2_COMB_CT_SM			((1 << COM2B1) | (1 << COM2B1))
#define TIMER2_COMB_MASK			((1 << COM2B1) | (1 << COM2B0))

/*
 * 										T/C2		Compare Output Mode, Phase Correct PWM Mode
 * COM2B1		COM2B0		Description
 * 0			0			Normal port operation, OC2B disconnected.
 * 
 * 0			1			Reserved
 * 
 * 1			0			Clear OC2B on Compare Match when up-counting. Set OC2B on Compare Match when down-counting.
 * 
 * 1			1			Set OC2B on Compare Match when up-counting. Clear OC2B on Compare Match when down-counting.
 */


/*
 *							T/C2	Clock source selection
 * CS22		CS21	CS20	Description
 * 0		0		0		OFF
 * 0		0		1		No prescaller
 * 0		1		0		8
 * 0		1		1		32
 * 1		0		0		64
 * 1		0		1		128
 * 1		1		0		256
 * 1		1		1		1024
 */

#define TIMER2_CLK_SRC_OFF		((0 << CS22) | (0 << CS21) | (0 << CS20))
#define TIMER2_CLK_SRC_1		((0 << CS22) | (0 << CS21) | (1 << CS20))
#define TIMER2_CLK_SRC_8		((0 << CS22) | (1 << CS21) | (0 << CS20))
#define TIMER2_CLK_SRC_32		((0 << CS22) | (1 << CS21) | (1 << CS20))
#define TIMER2_CLK_SRC_64		((1 << CS22) | (0 << CS21) | (0 << CS20))
#define TIMER2_CLK_SRC_128		((1 << CS22) | (0 << CS21) | (1 << CS20))
#define TIMER2_CLK_SRC_256		((1 << CS22) | (1 << CS21) | (0 << CS20))
#define TIMER2_CLK_SRC_1024		((1 << CS22) | (1 << CS21) | (1 << CS20))
#define TIMER2_CLK_SRC_MASK			((1 << CS22) | (1 << CS21) | (1 << CS20))

/*
 * 								TIMER/COUNTER[1345] Compare Output Mode, non-PWM
 *COMnx1	COMnx0		Description
 * 0		0			Normal port operation, OCnx disconnected
 * 
 * 0		1			Toggle OCnx on compare match
 * 
 * 1		0			Clear OCnx on compare match (set output to low level)
 * 
 * 1		1			Set OCnx on compare match (set output to high level)
 */

			//TIMER1
#define TIMER1_COMA_NORMAL		((0 << COM1A1) | (0 << COM1A0))
#define TIMER1_COMA_TOGGLE		((0 << COM1A1) | (1 << COM1A0))
#define TIMER1_COMA_CLEAR		((1 << COM1A1) | (0 << COM1A0))
#define TIMER1_COMA_SET			((1 << COM1A1) | (1 << COM1A0))
#define TIMER1_COMA_MASK		((1 << COM1A1) | (1 << COM1A0))

#define TIMER1_COMB_NORMAL		((0 << COM1B1) | (0 << COM1B0))
#define TIMER1_COMB_TOGGLE		((0 << COM1B1) | (1 << COM1B0))
#define TIMER1_COMB_CLEAR		((1 << COM1B1) | (0 << COM1B0))
#define TIMER1_COMB_SET			((1 << COM1B1) | (1 << COM1B0))
#define TIMER1_COMB_MASK		((1 << COM1B1) | (1 << COM1B0))

#define TIMER1_COMC_NORMAL		((0 << COM1C1) | (0 << COM1C0))
#define TIMER1_COMC_TOGGLE		((0 << COM1C1) | (1 << COM1C0))
#define TIMER1_COMC_CLEAR		((1 << COM1C1) | (0 << COM1C0))
#define TIMER1_COMC_SET			((1 << COM1C1) | (1 << COM1C0))
#define TIMER1_COMC_MASK		((1 << COM1C1) | (1 << COM1C0))

			//TIMER3
#define TIMER3_COMA_NORMAL		((0 << COM3A1) | (0 << COM3A0))
#define TIMER3_COMA_TOGGLE		((0 << COM3A1) | (0 << COM3A0))
#define TIMER3_COMA_CLEAR		((1 << COM3A1) | (0 << COM3A0))
#define TIMER3_COMA_SET			((1 << COM3A1) | (1 << COM3A0))
#define TIMER3_COMA_MASK		((1 << COM3A1) | (1 << COM3A0))

#define TIMER3_COMB_NORMAL		((0 << COM3B1) | (0 << COM3B0))
#define TIMER3_COMB_TOGGLE		((0 << COM3B1) | (0 << COM3B0))
#define TIMER3_COMB_CLEAR		((1 << COM3B1) | (0 << COM3B0))
#define TIMER3_COMB_SET			((1 << COM3B1) | (1 << COM3B0))
#define TIMER3_COMB_MASK		((1 << COM3B1) | (1 << COM3B0))

#define TIMER3_COMC_NORMAL		((0 << COM3C1) | (0 << COM3C0))
#define TIMER3_COMC_TOGGLE		((0 << COM3C1) | (0 << COM3C0))
#define TIMER3_COMC_CLEAR		((1 << COM3C1) | (0 << COM3C0))
#define TIMER3_COMC_NPWM_SET	((1 << COM3C1) | (1 << COM3C0))

			//TIMER4
#define TIMER4_COMA_NORMAL		((0 << COM4A1) | (0 << COM4A0))
#define TIMER4_COMA_TOGGLE		((0 << COM4A1) | (0 << COM4A0))
#define TIMER4_COMA_CLEAR		((1 << COM4A1) | (0 << COM4A0))
#define TIMER4_COMA_SET			((1 << COM4A1) | (1 << COM4A0))
#define TIMER4_COMA_MASK		((1 << COM4A1) | (1 << COM4A0))

#define TIMER4_COMB_NORMAL		((0 << COM4B1) | (0 << COM4B0))
#define TIMER4_COMB_TOGGLE		((0 << COM4B1) | (0 << COM4B0))
#define TIMER4_COMB_CLEAR		((1 << COM4B1) | (0 << COM4B0))
#define TIMER4_COMB_SET			((1 << COM4B1) | (1 << COM4B0))
#define TIMER4_COMB_MASK		((1 << COM4B1) | (1 << COM4B0))

#define TIMER4_COMC_NORMAL		((0 << COM4C1) | (0 << COM4C0))
#define TIMER4_COMC_TOGGLE		((0 << COM4C1) | (0 << COM4C0))
#define TIMER4_COMC_CLEAR		((1 << COM4C1) | (0 << COM4C0))
#define TIMER4_COMC_SET			((1 << COM4C1) | (1 << COM4C0))

			//TIMER5
#define TIMER5_COMA_NORMAL		((0 << COM5A1) | (0 << COM5A0))
#define TIMER5_COMA_TOGGLE		((0 << COM5A1) | (0 << COM5A0))
#define TIMER5_COMA_CLEAR		((1 << COM5A1) | (0 << COM5A0))
#define TIMER5_COMA_SET			((1 << COM5A1) | (1 << COM5A0))
#define TIMER5_COMA_MASK		((1 << COM5A1) | (1 << COM5A0))

#define TIMER5_COMB_NORMAL		((0 << COM5B1) | (0 << COM5B0))
#define TIMER5_COMB_TOGGLE		((0 << COM5B1) | (0 << COM5B0))
#define TIMER5_COMB_CLEAR		((1 << COM5B1) | (0 << COM5B0))
#define TIMER5_COMB_SET			((1 << COM5B1) | (1 << COM5B0))
#define TIMER5_COMB_MASK		((1 << COM5B1) | (1 << COM5B0))

#define TIMER5_COMC_NORMAL		((0 << COM5C1) | (0 << COM5C0))
#define TIMER5_COMC_TOGGLE		((0 << COM5C1) | (0 << COM5C0))
#define TIMER5_COMC_CLEAR		((1 << COM5C1) | (0 << COM5C0))
#define TIMER5_COMC_SET			((1 << COM5C1) | (1 << COM5C0))
#define TIMER5_COMC_MASK		((1 << COM5C1) | (1 << COM5C0))

/*
 * 								TIMER/COUNTER[1345] Compare Output Mode, Fast PWM
 *COMnx1	COMnx0		Description
 * 0		0			Normal port operation, OCnx disconnected
 *
 * 0		1			WGM13:0 = 14 or 15: Toggle OC1A on 
 * 						Compare Match, OC1B and OC1C 
 * 						disconnected (normal port operation). For all 
 * 						other WGM1 settings, normal port operation, 
 * 						OC1A/OC1B/OC1C disconnected.
 *
 * 1		0			Clear OCnA/OCnB/OCnC on compare match, set OCnA/OCnB/OCnC at TOP
 *
 * 1		1			Set OCnA/OCnB/OCnC on compare match, clear OCnA/OCnB/OCnC at TOP
 */

				//TIMER1
#define TIMER1_COMA_NORMAL		((0 << COM1A1) | (0 << COM1A0))
#define TIMER1_COMA_WGM_SET		((0 << COM1A1) | (1 << COM1A0))
#define TIMER1_COMA_CM_ST		((1 << COM1A1) | (0 << COM1A0))
#define TIMER1_COMA_SM_CT		((1 << COM1A1) | (1 << COM1A0))
#define TIMER1_COMA_MASK		((1 << COM1A1) | (1 << COM1A0))

#define TIMER1_COMB_NORMAL		((0 << COM1B1) | (0 << COM1B0))
#define TIMER1_COMB_WGM_SET		((0 << COM1B1) | (1 << COM1B0))
#define TIMER1_COMB_CM_ST		((1 << COM1B1) | (0 << COM1B0))
#define TIMER1_COMB_SM_CT		((1 << COM1B1) | (1 << COM1B0))
#define TIMER1_COMB_MASK		((1 << COM1B1) | (1 << COM1B0))

#define TIMER1_COMC_NORMAL		((0 << COM1C1) | (0 << COM1C0))
#define TIMER1_COMC_WGM_SET		((0 << COM1C1) | (1 << COM1C0))
#define TIMER1_COMC_CM_ST		((1 << COM1C1) | (0 << COM1C0))
#define TIMER1_COMC_SM_CT		((1 << COM1C1) | (1 << COM1C0))

				//TIMER3
#define TIMER3_COMA_NORMAL		((0 << COM3A1) | (0 << COM3A0))
#define TIMER3_COMA_WGM_SET		((0 << COM3A1) | (1 << COM3A0))
#define TIMER3_COMA_CM_ST		((1 << COM3A1) | (0 << COM3A0))
#define TIMER3_COMA_SM_CT		((1 << COM3A1) | (1 << COM3A0))
#define TIMER3_COMA_MASK		((1 << COM3A1) | (1 << COM3A0))
#define TIMER3_COMB_MASK		((1 << COM3B1) | (1 << COM3B0))

#define TIMER3_COMB_NORMAL		((0 << COM3B1) | (0 << COM3B0))
#define TIMER3_COMB_WGM_SET		((0 << COM3B1) | (1 << COM3B0))
#define TIMER3_COMB_CM_ST		((1 << COM3B1) | (0 << COM3B0))
#define TIMER3_COMB_SM_CT		((1 << COM3B1) | (1 << COM3B0))

#define TIMER3_COMC_NORMAL		((0 << COM3C1) | (0 << COM3C0))
#define TIMER3_COMC_WGM_SET		((0 << COM3C1) | (1 << COM3C0))
#define TIMER3_COMC_CM_ST		((1 << COM3C1) | (0 << COM3C0))
#define TIMER3_COMC_SM_CT		((1 << COM3C1) | (1 << COM3C0))
#define TIMER3_COMC_MASK		((1 << COM3C1) | (1 << COM3C0))

				//TIMER4
#define TIMER4_COMA_NORMAL		((0 << COM4A1) | (0 << COM4A0))
#define TIMER4_COMA_WGM_SET		((0 << COM4A1) | (1 << COM4A0))
#define TIMER4_COMA_CM_ST		((1 << COM4A1) | (0 << COM4A0))
#define TIMER4_COMA_SM_CT		((1 << COM4A1) | (1 << COM4A0))
#define TIMER4_COMA_MASK		((1 << COM4A1) | (1 << COM4A0))

#define TIMER4_COMB_NORMAL		((0 << COM4B1) | (0 << COM4B0))
#define TIMER4_COMB_WGM_SET		((0 << COM4B1) | (1 << COM4B0))
#define TIMER4_COMB_CM_ST		((1 << COM4B1) | (0 << COM4B0))
#define TIMER4_COMB_SM_CT		((1 << COM4B1) | (1 << COM4B0))
#define TIMER4_COMB_MASK		((1 << COM4B1) | (1 << COM4B0))

#define TIMER4_COMC_NORMAL		((0 << COM4C1) | (0 << COM4C0))
#define TIMER4_COMC_WGM_SET		((0 << COM4C1) | (1 << COM4C0))
#define TIMER4_COMC_CM_ST		((1 << COM4C1) | (0 << COM4C0))
#define TIMER4_COMC_SM_CT		((1 << COM4C1) | (1 << COM4C0))
#define TIMER4_COMC_MASK		((1 << COM4C1) | (1 << COM4C1))

				//TIMER5
#define TIMER5_COMA_NORMAL		((0 << COM5A1) | (0 << COM5A0))
#define TIMER5_COMA_WGM_SET		((0 << COM5A1) | (1 << COM5A0))
#define TIMER5_COMA_CM_ST		((1 << COM5A1) | (0 << COM5A0))
#define TIMER5_COMA_SM_CT		((1 << COM5A1) | (1 << COM5A0))
#define TIMER5_COMA_MASK		((1 << COM5A1) | (1 << COM5A0))

#define TIMER5_COMB_NORMAL		((0 << COM5B1) | (0 << COM5B0))
#define TIMER5_COMB_WGM_SET		((0 << COM5B1) | (1 << COM5B0))
#define TIMER5_COMB_CM_ST		((1 << COM5B1) | (0 << COM5B0))
#define TIMER5_COMB_SM_CT		((1 << COM5B1) | (1 << COM5B0))
#define TIMER5_COMB_MASK		((1 << COM5B1) | (1 << COM5B0))

#define TIMER5_COMC_NORMAL		((0 << COM5C1) | (0 << COM5C0))
#define TIMER5_COMC_WGM_SET		((0 << COM5C1) | (1 << COM5C0))
#define TIMER5_COMC_CM_ST		((1 << COM5C1) | (0 << COM5C0))
#define TIMER5_COMC_SM_CT		((1 << COM5C1) | (1 << COM5C0))




/*
 * 								TIMER/COUNTER[1345] Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
 *COMnx1	COMnx0		Description
 * 0		0			Normal port operation, OCnx disconnected
 *
 * 0		1			WGM13:0 = 8, 9 10 or 11: Toggle OC1A on 
 * 						Compare Match, OC1B and OC1C 
 * 						disconnected (normal port operation). For all 
 * 						other WGM1 settings, normal port operation, 
 * 						OC1A/OC1B/OC1C disconnected.
 * 						OC1A/OC1B/OC1C disconnected.
 *
 * 1		0			Clear OCnA/OCnB/OCnC on compare 
 * 						match when up-counting. Set 
 * 						OCnA/OCnB/OCnC on compare match 
 * 						when downcounting.
 *
 * 1		1			Set OCnA/OCnB/OCnC on compare match 
 * 						when up-counting. Clear 
 * 						OCnA/OCnB/OCnC on compare match 
 * 						when downcounting.
 */
						//TIMER1
#define TIMER1_COMA_NORMAL			((0 << COM1A1) | (0 << COM1A0))
#define TIMER1_COMA_WGM_SET			((0 << COM1A1) | (1 << COM1A0))
#define TIMER1_COMA_CMUC_SMDC		((1 << COM1A1) | (0 << COM1A0))
#define TIMER1_COMA_SMUC_CMDC		((1 << COM1A1) | (1 << COM1A0))

#define TIMER1_COMB_NORMAL			((0 << COM1B1) | (0 << COM1B0))
#define TIMER1_COMB_WGM_SET			((0 << COM1B1) | (1 << COM1B0))
#define TIMER1_COMB_CMUC_SMDC		((1 << COM1B1) | (0 << COM1B0))
#define TIMER1_COMB_SMUC_CMDC		((1 << COM1B1) | (1 << COM1B0))

#define TIMER1_COMC_NORMAL			((0 << COM1C1) | (0 << COM1C0))
#define TIMER1_COMC_WGM_SET			((0 << COM1C1) | (1 << COM1C0))
#define TIMER1_COMC_CMUC_SMDC		((1 << COM1C1) | (0 << COM1C0))
#define TIMER1_COMC_SMUC_CMDC		((1 << COM1C1) | (1 << COM1C0))

						//TIMER3
#define TIMER3_COMA_NORMAL			((0 << COM3A1) | (0 << COM3A0))
#define TIMER3_COMA_WGM_SET			((0 << COM3A1) | (1 << COM3A0))
#define TIMER3_COMA_CMUC_SMDC		((1 << COM3A1) | (0 << COM3A0))
#define TIMER3_COMA_SMUC_CMDC		((1 << COM3A1) | (1 << COM3A0))

#define TIMER3_COMB_NORMAL			((0 << COM3B1) | (0 << COM3B0))
#define TIMER3_COMB_WGM_SET			((0 << COM3B1) | (1 << COM3B0))
#define TIMER3_COMB_CMUC_SMDC		((1 << COM3B1) | (0 << COM3B0))
#define TIMER3_COMB_SMUC_CMDC		((1 << COM3B1) | (1 << COM3B0))

#define TIMER3_COMC_NORMAL			((0 << COM3C1) | (0 << COM3C0))
#define TIMER3_COMC_WGM_SET			((0 << COM3C1) | (1 << COM3C0))
#define TIMER3_COMC_CMUC_SMDC		((1 << COM3C1) | (0 << COM3C0))
#define TIMER3_COMC_SMUC_CMDC		((1 << COM3C1) | (1 << COM3C0))

						//TIMER4
#define TIMER4_COMA_NORMAL			((0 << COM4A1) | (0 << COM4A0))
#define TIMER4_COMA_WGM_SET			((0 << COM4A1) | (1 << COM4A0))
#define TIMER4_COMA_CMUC_SMDC		((1 << COM4A1) | (0 << COM4A0))
#define TIMER4_COMA_SMUC_CMDC		((1 << COM4A1) | (1 << COM4A0))

#define TIMER4_COMB_NORMAL			((0 << COM4B1) | (0 << COM4B0))
#define TIMER4_COMB_WGM_SET			((0 << COM4B1) | (1 << COM4B0))
#define TIMER4_COMB_CMUC_SMDC		((1 << COM4B1) | (0 << COM4B0))
#define TIMER4_COMB_SMUC_CMDC		((1 << COM4B1) | (1 << COM4B0))

#define TIMER4_COMC_NORMAL			((0 << COM4C1) | (0 << COM4C0))
#define TIMER4_COMC_WGM_SET			((0 << COM4C1) | (1 << COM4C0))
#define TIMER4_COMC_CMUC_SMDC		((1 << COM4C1) | (0 << COM4C0))
#define TIMER4_COMC_SMUC_CMDC		((1 << COM4C1) | (1 << COM4C0))

						//TIMER5
#define TIMER5_COMA_NORMAL			((0 << COM5A1) | (0 << COM5A0))
#define TIMER5_COMA_WGM_SET			((0 << COM5A1) | (1 << COM5A0))
#define TIMER5_COMA_CMUC_SMDC		((1 << COM5A1) | (0 << COM5A0))
#define TIMER5_COMA_SMUC_CMDC		((1 << COM5A1) | (1 << COM5A0))

#define TIMER5_COMB_NORMAL			((0 << COM5B1) | (0 << COM5B0))
#define TIMER5_COMB_WGM_SET			((0 << COM5B1) | (1 << COM5B0))
#define TIMER5_COMB_CMUC_SMDC		((1 << COM5B1) | (0 << COM5B0))
#define TIMER5_COMB_SMUC_CMDC		((1 << COM5B1) | (1 << COM5B0))

#define TIMER5_COMC_NORMAL			((0 << COM5C1) | (0 << COM5C0))
#define TIMER5_COMC_WGM_SET			((0 << COM5C1) | (1 << COM5C0))
#define TIMER5_COMC_CMUC_SMDC		((1 << COM5C1) | (0 << COM5C0))
#define TIMER5_COMC_SMUC_CMDC		((1 << COM5C1) | (1 << COM5C0))


/*
 *								TIMER/COUNTER[1345] Waveform Generation Mode Bit Description
 * Mode 	WGMn3 	WGMn2	WGMn1	WGMn0	T/C Mode of operation 	TOP			Update of OCRnx at 		TOVn flag set on
 * 0		0		0		0		0		Normal 					0xFFFF 		Immediate 				MAX
 * 1		0		0		0		1		PWM PHC 8bit			0x00FF 		TOP						BOTTOM
 * 2		0		0		1		0		PWM PHC 9bit			0x01FF 		TOP						BOTTOM
 * 3		0		0		1		1		PWM PHC 10bit			0x03FF 		TOP						BOTTOM
 * 4		0		1		0		0		CTC						OCRnA 		Immediate				MAX
 * 5		0		1		0		1		Fast PWM 8bit			0x00FF 		TOP						TOP
 * 6		0		1		1		0		Fast PWM 9bit			0x01FF 		TOP						TOP
 * 7		0		1		1		1		Fast PWM 10bit			0x03FF 		TOP						TOP
 * 8		1		0		0		0		PWM PHFC				ICRn 		BOTTOM					BOTTOM
 * 9		1		0		0		1		PWM PHFC				OCRnA 		BOTTOM					BOTTOM
 * 10		1		0		1		0		PWM PHC 				ICRn 		TOP						BOTTOM
 * 11		1		0		1		1		PWM PHC 				OCRnA 		TOP						BOTTOM
 * 12		1		1		0		0		CTC						ICRn 		Immediate				MAX
 * 13		1		1		0		1		Reverced				----- 		----					----
 * 14		1		1		1		0		FPWM					ICRn 		TOP						TOP
 * 15		1		1		1		1		FPWM					OCRnA 		TOP						TOP
 */

						//TIMER1
#define TIMER1_WF_NORMAL 				((0 << WGM13) | (0 << WGM12) | (0 << WGM11) | (0 << WGM10))
#define TIMER1_WF_PWM_PHC_8B			((0 << WGM13) | (0 << WGM12) | (0 << WGM11) | (1 << WGM10))
#define TIMER1_WF_PWM_PHC_9B			((0 << WGM13) | (0 << WGM12) | (1 << WGM11) | (0 << WGM10))
#define TIMER1_WF_PWM_PHC_10B			((0 << WGM13) | (0 << WGM12) | (1 << WGM11) | (1 << WGM10))
#define TIMER1_WF_CTC_TOPOCR1A			((0 << WGM13) | (1 << WGM12) | (0 << WGM11) | (0 << WGM10))
#define TIMER1_WF_FPWM_8B 				((0 << WGM13) | (1 << WGM12) | (0 << WGM11) | (1 << WGM10))
#define TIMER1_WF_FPWM_9B 				((0 << WGM13) | (1 << WGM12) | (1 << WGM11) | (0 << WGM10))
#define TIMER1_WF_FPWM_10B 				((0 << WGM13) | (1 << WGM12) | (1 << WGM11) | (1 << WGM10))
#define TIMER1_WF_PWM_PHFC_TOPICR1		((1 << WGM13) | (0 << WGM12) | (0 << WGM11) | (0 << WGM10))
#define TIMER1_WF_PWM_PHFC_TOPOCR1A		((1 << WGM13) | (0 << WGM12) | (0 << WGM11) | (1 << WGM10))
#define TIMER1_WF_PWM_PHC_TOPICR1 		((1 << WGM13) | (0 << WGM12) | (1 << WGM11) | (0 << WGM10))
#define TIMER1_WF_PWM_PHC_TOPOCR1A 		((1 << WGM13) | (0 << WGM12) | (1 << WGM11) | (1 << WGM10))
#define TIMER1_WF_CTC_TOPICR1			((1 << WGM13) | (1 << WGM12) | (0 << WGM11) | (0 << WGM10))
#define TIMER1_WF_FPWM_TOPICR1			((1 << WGM13) | (1 << WGM12) | (1 << WGM11) | (0 << WGM10))
#define TIMER1_WF_FPWM_TOPOCR1A			((1 << WGM13) | (1 << WGM12) | (1 << WGM11) | (1 << WGM10))
#define TIMER1_WF_MASK					((1 << WGM13) | (1 << WGM12) | (1 << WGM11) | (1 << WGM10))

						//TIMER3
#define TIMER3_WF_NORMAL 				((0 << WGM33) | (0 << WGM32) | (0 << WGM31) | (0 << WGM30))
#define TIMER3_WF_PWM_PHC_8B			((0 << WGM33) | (0 << WGM32) | (0 << WGM31) | (1 << WGM30))
#define TIMER3_WF_PWM_PHC_9B			((0 << WGM33) | (0 << WGM32) | (1 << WGM31) | (0 << WGM30))
#define TIMER3_WF_PWM_PHC_10B			((0 << WGM33) | (0 << WGM32) | (1 << WGM31) | (1 << WGM30))
#define TIMER3_WF_CTC_TOPOCR3A			((0 << WGM33) | (1 << WGM32) | (0 << WGM31) | (0 << WGM30))
#define TIMER3_WF_FPWM_8B 				((0 << WGM33) | (1 << WGM32) | (0 << WGM31) | (1 << WGM30))
#define TIMER3_WF_FPWM_9B 				((0 << WGM33) | (1 << WGM32) | (1 << WGM31) | (0 << WGM30))
#define TIMER3_WF_FPWM_10B 				((0 << WGM33) | (1 << WGM32) | (1 << WGM31) | (1 << WGM30))
#define TIMER3_WF_PWM_PHFC_TOPICR3		((1 << WGM33) | (0 << WGM32) | (0 << WGM31) | (0 << WGM30))
#define TIMER3_WF_PWM_PHFC_TOPOCR3A		((1 << WGM33) | (0 << WGM32) | (0 << WGM31) | (1 << WGM30))
#define TIMER3_WF_PWM_PHC_TOPICR1 		((1 << WGM33) | (0 << WGM32) | (1 << WGM31) | (0 << WGM30))
#define TIMER3_WF_PWM_PHC_TOPOCR3A 		((1 << WGM33) | (0 << WGM32) | (1 << WGM31) | (1 << WGM30))
#define TIMER3_WF_CTC_TOPICR3			((1 << WGM33) | (1 << WGM32) | (0 << WGM31) | (0 << WGM30))
#define TIMER3_WF_FPWM_TOPICR3			((1 << WGM33) | (1 << WGM32) | (1 << WGM31) | (0 << WGM30))
#define TIMER3_WF_FPWM_TOPOCR3A			((1 << WGM33) | (1 << WGM32) | (1 << WGM31) | (1 << WGM30))
#define TIMER3_WF_MASK					((1 << WGM33) | (1 << WGM32) | (1 << WGM31) | (1 << WGM30))

						//TIMER4
#define TIMER4_WF_NORMAL 				((0 << WGM43) | (0 << WGM42) | (0 << WGM41) | (0 << WGM40))
#define TIMER4_WF_PWM_PHC_8B			((0 << WGM43) | (0 << WGM42) | (0 << WGM41) | (1 << WGM40))
#define TIMER4_WF_PWM_PHC_9B			((0 << WGM43) | (0 << WGM42) | (1 << WGM41) | (0 << WGM40))
#define TIMER4_WF_PWM_PHC_10B			((0 << WGM43) | (0 << WGM42) | (1 << WGM41) | (1 << WGM40))
#define TIMER4_WF_CTC_TOPOCR4A			((0 << WGM43) | (1 << WGM42) | (0 << WGM41) | (0 << WGM40))
#define TIMER4_WF_FPWM_8B 				((0 << WGM43) | (1 << WGM42) | (0 << WGM41) | (1 << WGM40))
#define TIMER4_WF_FPWM_9B 				((0 << WGM43) | (1 << WGM42) | (1 << WGM41) | (0 << WGM40))
#define TIMER4_WF_FPWM_10B 				((0 << WGM43) | (1 << WGM42) | (1 << WGM41) | (1 << WGM40))
#define TIMER4_WF_PWM_PHFC_TOPICR4		((1 << WGM43) | (0 << WGM42) | (0 << WGM41) | (0 << WGM40))
#define TIMER4_WF_PWM_PHFC_TOPOCR4A		((1 << WGM43) | (0 << WGM42) | (0 << WGM41) | (1 << WGM40))
#define TIMER4_WF_PWM_PHC_TOPICR4 		((1 << WGM43) | (0 << WGM42) | (1 << WGM41) | (0 << WGM40))
#define TIMER4_WF_PWM_PHC_TOPOCR4A 		((1 << WGM43) | (0 << WGM42) | (1 << WGM41) | (1 << WGM40))
#define TIMER4_WF_CTC_TOPICR4			((1 << WGM43) | (1 << WGM42) | (0 << WGM41) | (0 << WGM40))
#define TIMER4_WF_FPWM_TOPICR4			((1 << WGM43) | (1 << WGM42) | (1 << WGM41) | (0 << WGM40))
#define TIMER4_WF_FPWM_TOPOCR4A			((1 << WGM43) | (1 << WGM42) | (1 << WGM41) | (1 << WGM40))
#define TIMER4_WF_MASK					((1 << WGM43) | (1 << WGM42) | (1 << WGM41) | (1 << WGM40))

						//TIMER5
#define TIMER5_WF_NORMAL 				((0 << WGM53) | (0 << WGM52) | (0 << WGM51) | (0 << WGM53))
#define TIMER5_WF_PWM_PHC_8B			((0 << WGM53) | (0 << WGM52) | (0 << WGM51) | (1 << WGM53))
#define TIMER5_WF_PWM_PHC_9B			((0 << WGM53) | (0 << WGM52) | (1 << WGM51) | (0 << WGM53))
#define TIMER5_WF_PWM_PHC_10B			((0 << WGM53) | (0 << WGM52) | (1 << WGM51) | (1 << WGM53))
#define TIMER5_WF_CTC_TOPOCR5A			((0 << WGM53) | (1 << WGM52) | (0 << WGM51) | (0 << WGM53))
#define TIMER5_WF_FPWM_8B 				((0 << WGM53) | (1 << WGM52) | (0 << WGM51) | (1 << WGM53))
#define TIMER5_WF_FPWM_9B 				((0 << WGM53) | (1 << WGM52) | (1 << WGM51) | (0 << WGM53))
#define TIMER5_WF_FPWM_10B 				((0 << WGM53) | (1 << WGM52) | (1 << WGM51) | (1 << WGM53))
#define TIMER5_WF_PWM_PHFC_TOPICR5		((1 << WGM53) | (0 << WGM52) | (0 << WGM51) | (0 << WGM53))
#define TIMER5_WF_PWM_PHFC_TOPOCR5A		((1 << WGM53) | (0 << WGM52) | (0 << WGM51) | (1 << WGM53))
#define TIMER5_WF_PWM_PHC_TOPICR5 		((1 << WGM53) | (0 << WGM52) | (1 << WGM51) | (0 << WGM53))
#define TIMER5_WF_PWM_PHC_TOPOCR5A 		((1 << WGM53) | (0 << WGM52) | (1 << WGM51) | (1 << WGM53))
#define TIMER5_WF_CTC_TOPICR5			((1 << WGM53) | (1 << WGM52) | (0 << WGM51) | (0 << WGM53))
#define TIMER5_WF_FPWM_TOPICR5			((1 << WGM53) | (1 << WGM52) | (1 << WGM51) | (0 << WGM53))
#define TIMER5_WF_FPWM_TOPOCR5A			((1 << WGM53) | (1 << WGM52) | (1 << WGM51) | (1 << WGM53))
#define TIMER5_WF_MASK					((1 << WGM53) | (1 << WGM52) | (1 << WGM51) | (1 << WGM53))



/*
 *								TIMER/COUNTER[1345] Clock select bit description
 *	CSn2	CSn1	CSn0		Desc
 *	1		0		0			No clock src
 *	1		0		1			clk/1
 *	1		1		0			clk/8
 *	1		1		1			clk/64
 *	0		0		0			clk/256
 *	0		0		1			clk/1024
 *	0		1		0			EXT src on Tn pin, falling edge
 *	0		1		1			EXT src on Tn pin, rising edge
 */
									//TIMER1
#define TIMER1_CLK_SRC_NO				((0 << CS12) | (0 << CS11) | (0 << CS10))
#define TIMER1_CLK_SRC_1				((0 << CS12) | (0 << CS11) | (1 << CS10))
#define TIMER1_CLK_SRC_8				((0 << CS12) | (1 << CS11) | (0 << CS10))
#define TIMER1_CLK_SRC_64				((0 << CS12) | (1 << CS11) | (1 << CS10))
#define TIMER1_CLK_SRC_256				((1 << CS12) | (0 << CS11) | (0 << CS10))
#define TIMER1_CLK_SRC_1024				((1 << CS12) | (0 << CS11) | (1 << CS10))
#define TIMER1_CLK_SRC_EXT_FALLING		((1 << CS12) | (1 << CS11) | (0 << CS10))
#define TIMER1_CLK_SRC_EXT_RISING		((1 << CS12) | (1 << CS11) | (1 << CS10))
#define TIMER1_CLK_SRC_MASK				((1 << CS12) | (1 << CS11) | (1 << CS10))

									//TIMER3
#define TIMER3_CLK_SRC_NO				((1 << CS32) | (0 << CS31) | (0 << CS30))
#define TIMER3_CLK_SRC_1				((1 << CS32) | (0 << CS31) | (1 << CS30))
#define TIMER3_CLK_SRC_8				((1 << CS32) | (1 << CS31) | (0 << CS30))
#define TIMER3_CLK_SRC_64				((1 << CS32) | (1 << CS31) | (1 << CS30))
#define TIMER3_CLK_SRC_256				((0 << CS32) | (0 << CS31) | (0 << CS30))
#define TIMER3_CLK_SRC_1024				((0 << CS32) | (0 << CS31) | (1 << CS30))
#define TIMER3_CLK_SRC_EXT_FALLING		((0 << CS32) | (1 << CS31) | (0 << CS30))
#define TIMER3_CLK_SRC_EXT_RISING		((0 << CS32) | (1 << CS31) | (1 << CS30))
#define TIMER3_CLK_SRC_MASK				((1 << CS32) | (1 << CS31) | (1 << CS30))

									//TIMER4
#define TIMER4_CLK_SRC_NO				((1 << CS42) | (0 << CS41) | (0 << CS40))
#define TIMER4_CLK_SRC_1				((1 << CS42) | (0 << CS41) | (1 << CS40))
#define TIMER4_CLK_SRC_8				((1 << CS42) | (1 << CS41) | (0 << CS40))
#define TIMER4_CLK_SRC_64				((1 << CS42) | (1 << CS41) | (1 << CS40))
#define TIMER4_CLK_SRC_256				((0 << CS42) | (0 << CS41) | (0 << CS40))
#define TIMER4_CLK_SRC_1024				((0 << CS42) | (0 << CS41) | (1 << CS40))
#define TIMER4_CLK_SRC_EXT_FALLING		((0 << CS42) | (1 << CS41) | (0 << CS40))
#define TIMER4_CLK_SRC_EXT_RISING		((0 << CS42) | (1 << CS41) | (1 << CS40))
#define TIMER4_CLK_SRC_MASK				((1 << CS42) | (1 << CS41) | (1 << CS40))

									//TIMER5
#define TIMER5_CLK_SRC_NO				((1 << CS52) | (0 << CS51) | (0 << CS50))
#define TIMER5_CLK_SRC_1				((1 << CS52) | (0 << CS51) | (1 << CS50))
#define TIMER5_CLK_SRC_8				((1 << CS52) | (1 << CS51) | (0 << CS50))
#define TIMER5_CLK_SRC_64				((1 << CS52) | (1 << CS51) | (1 << CS50))
#define TIMER5_CLK_SRC_256				((0 << CS52) | (0 << CS51) | (0 << CS50))
#define TIMER5_CLK_SRC_1024				((0 << CS52) | (0 << CS51) | (1 << CS50))
#define TIMER5_CLK_SRC_EXT_FALLING		((0 << CS52) | (1 << CS51) | (0 << CS50))
#define TIMER5_CLK_SRC_EXT_RISING		((0 << CS52) | (1 << CS51) | (1 << CS50))
#define TIMER5_CLK_SRC_MASK				((1 << CS52) | (1 << CS51) | (1 << CS50))

