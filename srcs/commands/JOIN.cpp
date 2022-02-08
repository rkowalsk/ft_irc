/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JOIN.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wperu <wperu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:56:20 by wperu             #+#    #+#             */
/*   Updated: 2022/02/08 01:56:20 by wperu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "JOIN.hpp"

join::join()
{   
}

join::~join()
{

}


void join::excute(std::string buf, Client *client, std::vector<Channel *> *chan, std::vector<pollfd> &fds)
{
    _get_cmd(buf);
    if (_cmd.size() < 2)
    {
        err_needmoreparams(*cli, fds, _cmd[0]);
        return;
    }
    if (_cmd[1][0] && _cmd[1][0] != '#')
		_cmd[1] = '#' + _cmd[1];
	if (_check_name(_cmd[1], chan))
	{
		channels->push_back(new Channel(_cmd[1]));
	}
	_join_chan(_cmd[1], cli, chan);
    
}

bool join::_check_name(std::string name, std::vector<Channel *> *channels)
{
    for (std::vector<Channel *>::iterator it = channels->begin(); it != channels->end(); it++)
	{
		Channel *c = *it;
		if (c->get_name() == name)
			return false;
	}
	return true;
}

void	join::_joinChan(std::string name, Client *cli, std::vector<Channel *> *channels, std::vector<pollfd> &fds)
{
	bool new_cli = false;
	std::string tmp;
    Channel *chan = _get_Chan(name, channels);

    if (chan->is_members(cli))
	{
		err_useronchannel(*cli,fds,name);
		return;
    }
    else
    {
        chan->add_Client(cli);
	    if (chan->get_all_users().size() == 1)
			chan->add_operator_user(cli);
		new_cli = true;
    }

    _inform_members(name, cli, chan);

    if(new_cli)
    {
        rpl_topic(*cli, fds, name, chan->get_topic());
    }
}

void	join::_inform_members(std::string name, Client *cli, Channel *chan)
{
	std::string message = ":" + cli->get_nickname() + "!" + cli->get_name() + "@" + cli->get_ip() + " JOIN " + name + "\r\n";
	std::vector<Client*> members = chan->get_Members();
	for (std::vector<client*>::iterator it = members.begin(); it != members.end(); it++)
	{
		Client *c = *it;
	//	send();
    }
}