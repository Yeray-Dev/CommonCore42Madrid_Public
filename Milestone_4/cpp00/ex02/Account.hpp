// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void ); // Devuelve numero de cuentas // ?
	static int	getTotalAmount( void ); // Devuelve el total de dinero
	static int	getNbDeposits( void ); // Devuelve el numero depositos total.
	static int	getNbWithdrawals( void ); // Devuelve la cantidad retirada
	static void	displayAccountsInfos( void ); // Imprime la informacion de las cuentas

	Account( int initial_deposit ); // Constructor // ?
	~Account( void ); // Destructor

	void	makeDeposit( int deposit ); // Hacer Deposito
	bool	makeWithdrawal( int withdrawal ); // Retirar Deposito
	int		checkAmount( void ) const; // Chekea Cantidad 
	void	displayStatus( void ) const; // Imprime el estado de una cuenta


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void ); // Fecha y hora

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
