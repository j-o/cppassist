
#pragma once


#include <cppassist/cmdline/CommandLineAction.h>
#include <cppassist/cmdline/CommandLineCommand.h>
#include <cppassist/cmdline/CommandLineOption.h>
#include <cppassist/cmdline/CommandLineParameter.h>


class Program;


/**
*  @brief
*    Command 'count'
*/
class ActionCount : public cppassist::CommandLineAction
{
public:
    /**
    *  @brief
    *    Constructor
    *
    *  @param[in] program
    *    Main program
    */
    ActionCount(Program & program);

    /**
    *  @brief
    *    Destructor
    */
    ~ActionCount();

    // Virtual cppassist::CommandLineAction functions
    virtual int execute() override;


protected:
    Program                         & m_program;
    cppassist::CommandLineCommand     m_commandCount;
    cppassist::CommandLineOption      m_optionStep;
    cppassist::CommandLineParameter   m_paramFrom;
    cppassist::CommandLineParameter   m_paramTo;
};
