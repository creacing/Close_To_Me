<template>
  <nav class="pagination">
    <span class="prev" @click="prePage" v-if="curPageList[0]>2">
      <i class="ic i-angle-left" aria-label="上一页"></i>
    </span>

    <span class="page-number" :class="currentIndex === 1?'current':''" @click="toPage(1)">1</span>

    <span class="space" v-if="curPageList[0]!==2">…</span>

    <span
      class="page-number"
      @click="toPage(index)"
      v-for="index in curPageList"
      :key="index"
      :class="currentIndex === index?'current':''"
    >{{index}}</span>

    <span class="space" v-if="curPageList[2]!==pageNum">…</span>

    <span
      class="page-number"
      :class="currentIndex === pageNum?'current':''"
      @click="toPage(pageNum)"
    >{{pageNum}}</span>

    <span class="next" @click="nextPage" v-if="curPageList[2]<pageNum">
      <i class="ic i-angle-right" aria-label="下一页"></i>
    </span>
  </nav>
</template>
<script setup>
import { defineProps, toRefs, defineEmits, ref } from 'vue'
import { RouterLink } from "vue-router";

const curPageList = ref([2, 3, 4])

const currentIndex = ref(1)

const props = defineProps({
  pageNum: {
    type: Number,
    default: 0
  }
})

const emits = defineEmits(['getCurIndex'])

const { pageNum } = toRefs(props)

const nextPage = () => {
  const last = curPageList.value[2]
  const temp = []
  if (last + 1 > pageNum) {

    for (let i = last + 1; i < pageNum; i++) {
      temp.push(i)
    }
    curPageList.value = temp
  } else {

    curPageList.value = [last + 1, last + 2, last + 3]
  }


}
const prePage = () => {
  const first = curPageList.value[0]
  const temp = []
  if (first - 3 < 1) {

    for (let i = 2; i < first; i++) {
      temp.push(i)
    }
    curPageList.value = temp
  } else {

    curPageList.value = [first - 3, first - 2, first - 1]
  }
}
const toPage = (pageIndex) => {
  currentIndex.value = pageIndex
  emits("getCurIndex", pageIndex);
}
</script>

<style scoped lang='scss'>
.pagination .next:hover,
.pagination .page-number.current,
.pagination .page-number:hover,
.pagination .prev:hover {
  color: var(--grey-0);
  background-color: var(--color-young-blue);
  box-shadow: 0 0.125rem 0.75rem var(--color-young-blue);
  opacity: 0.9;
  border-radius: 0.625rem;
}

.pagination .next,
.pagination .page-number,
.pagination .prev,
.pagination .space {
  display: inline-block;
  margin: 0 0.5rem;
  padding: 0 0.75rem;
  position: relative;
  border-radius: 0.3125rem;
}

@media (max-width: 767px) {
  .pagination .next,
  .pagination .page-number,
  .pagination .prev,
  .pagination .space {
    margin: 0 0.3125rem;
  }
}

.pagination {
  width: 100%;
  padding: 1.25rem 3.125rem;
  text-align: center;
  display: inline-block;
  color: var(--grey-5);
}

@media (max-width: 767px) {
  .pagination {
    padding: 1.25rem 0.625rem;
  }
}

.pagination .next,
.pagination .page-number,
.pagination .prev {
  transition: all 0.2s ease-in-out 0s;
}

.pagination .space {
  margin: 0;
  padding: 0;
}

.pagination .prev {
  margin-left: 0;
}

.pagination .next {
  margin-right: 0;
}

.pagination .page-number.current:hover {
  box-shadow: 0 0 0.3125rem var(--primary-color);
}
</style>
