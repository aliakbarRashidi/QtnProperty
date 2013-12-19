/*
 * Copyright (c) 2012 - 2013, the Qtinuum project.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * <qtinuum.team@gmail.com>
 */

#include "PropertyQFont.h"
#include <QFontDatabase>

namespace Qtinuum
{

PropertyQFontBase::PropertyQFontBase(QObject *parent)
    : SinglePropertyBase<QFont>(parent)
{
    addState(PropertyStateCollapsed);
}

bool PropertyQFontBase::fromStrImpl(const QString& str)
{
    QFont font;
    if (!font.fromString(str.trimmed()))
        return false;

    return setValue(font);
}

bool PropertyQFontBase::toStrImpl(QString& str) const
{
    QFont v = value();
    str = v.toString();
    return true;
}

} // end namespace Qtinuum
