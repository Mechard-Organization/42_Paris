/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:57:26 by mechard           #+#    #+#             */
/*   Updated: 2025/03/18 11:57:26 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
	{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm()
{}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw AForm::GradeTooLowException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "AForm: Form not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form " << form.getName() 
        << " [signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade required to sign: " << form.getGradeToSign()
        << ", grade required to execute: " << form.getGradeToExecute() << "]";
    return out;
}
