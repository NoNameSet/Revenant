#ifndef REVENANT_ATRTTI_H
#define REVENANT_ATRTTI_H

#pragma once

#include "rage.h"

#define RTTI_CLASS_STRING(_ClassId) #_ClassId
#define RTTI_CLASS_TO_STRING(_ClassId) RTTI_CLASS_STRING(_ClassId)

#define DECLARE_RTTI_BASE_CLASS_WITH_HASH_TYPE(_ClassId, _HashType) \
    public: \
        virtual bool GetIsClassId(const _HashType ClassId) const { return _ClassId::GetStaticClassId() == ClassId ? true : false; } \
        template<typename _ClassType> bool GetIsClass() const { return GetIsClassId(_ClassType::GetStaticClassId()); } \
		template <typename _ClassType> _ClassType* AsClass() { return GetIsClass<_ClassType>() ? static_cast<_ClassType*>(this) : nullptr; } \
		template <typename _ClassType> _ClassType const* AsClass() const { return GetIsClass<_ClassType>() ? static_cast<_ClassType const*>(this) : nullptr; } \
        virtual const _HashType GetClassId() const { return GetStaticClassId(); } \
		virtual const _HashType GetBaseClassId() const { return _HashType::Null(); } \
        static const _HashType GetStaticClassId() { return ms_ClassId_##_ClassId; } \
		static const _HashType GetStaticBaseClassId() { return _HashType::Null(); } \
        typedef _ClassId thisclass; \
		template<typename T__> \
		static bool RTTIExistsCheck(); \
    private: \
        static _HashType ms_ClassId_##_ClassId;

#define DECLARE_RTTI_BASE_CLASS(_ClassId) DECLARE_RTTI_BASE_CLASS_WITH_HASH_TYPE(_ClassId, rage::atHashString)

#define DECLARE_RTTI_DERIVED_CLASS_WITH_HASH_TYPE(_ClassId, _BaseClassId, _HashType) \
	public: \
		virtual bool GetIsClassId(const _HashType ClassId) const { return _ClassId::GetStaticClassId() == ClassId ? true : _BaseClassId::GetIsClassId(ClassId); } \
		virtual const _HashType GetClassId() const { return GetStaticClassId(); } \
		virtual const _HashType GetBaseClassId() const { return _BaseClassId::GetClassId(); } \
        static const _HashType GetStaticClassId() { return ms_ClassId_##_ClassId; } \
		static const _HashType GetStaticBaseClassId() { return _BaseClassId::GetStaticClassId(); } \
		typedef _ClassId thisclass; \
		typedef _BaseClassId superclass; \
		template<typename T__> \
		static bool RTTIExistsCheck(); \
	private: \
		static _HashType ms_ClassId_##_ClassId;

#define DECLARE_RTTI_DERIVED_CLASS(_ClassId, _BaseClassId) DECLARE_RTTI_DERIVED_CLASS_WITH_HASH_TYPE(_ClassId, _BaseClassId, rage::atHashString)

#define INSTANTIATE_RTTI_NAMESPACE_CLASS_WITH_HASH_TYPE(_NamespaceId, _ClassId, _HashId, _HashType) \
    _HashType _NamespaceId::_ClassId::ms_ClassId_##_ClassId(RTTI_CLASS_TO_STRING(_NamespaceId::_ClassId), _HashId);\
 	template<>\
 	bool _NamespaceId::_ClassId::RTTIExistsCheck<_NamespaceId::_ClassId>() { return true; }

#define INSTANTIATE_RTTI_NAMESPACE_CLASS(_NamespaceId, _ClassId, _HashId) INSTANTIATE_RTTI_NAMESPACE_CLASS_WITH_HASH_TYPE(_NamespaceId, _ClassId, _HashId, rage::atHashString)

#define DECLARE_RTTI_BASE_CLASS_WITH_ID(_ClassId, _Id) \
	public: \
		virtual bool GetIsClassId(const uint32_t ClassId) const { return _ClassId::GetStaticClassId() == ClassId ? true : false; } \
		template<typename _ClassType> bool GetIsClass() const { return GetIsClassId(_ClassType::GetStaticClassId()); } \
		template <typename _ClassType> _ClassType* AsClass() { return GetIsClass<_ClassType>() ? static_cast<_ClassType*>(this) : nullptr; } \
		template <typename _ClassType> _ClassType const* AsClass() const { return GetIsClass<_ClassType>() ? static_cast<_ClassType const*>(this) : nullptr; } \
		virtual const uint32_t GetClassId() const { return GetStaticClassId(); } \
		static const uint32_t GetStaticClassId() { return ms_ClassId_##_ClassId; } \
		typedef _ClassId thisclass; \
		template<typename T__> \
		static bool RTTIExistsCheck(); \
	private: \
		static const uint32_t ms_ClassId_##_ClassId = _Id;

#define DECLARE_RTTI_DERIVED_CLASS_WITH_ID(_ClassId, _BaseClassId, _Id) \
	public: \
		virtual bool GetIsClassId(const uint32_t ClassId) const { return _ClassId::GetStaticClassId() == ClassId ? true : _BaseClassId::GetIsClassId(ClassId); } \
		virtual const uint32_t GetClassId() const { return GetStaticClassId(); } \
		static const uint32_t GetStaticClassId() { return ms_ClassId_##_ClassId; } \
		typedef _ClassId thisclass; \
		typedef _BaseClassId superclass; \
		template<typename T__> \
		static bool RTTIExistsCheck(); \
	private: \
		static const uint32_t ms_ClassId_##_ClassId = _Id;

#endif //REVENANT_ATRTTI_H